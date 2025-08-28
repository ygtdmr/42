#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>

/* senin fonksiyonun */
int picoshell(char **cmds[]);

/* ---------------- FD Leak Helper ---------------- */
int count_open_fds(void)
{
    int count = 0;
    DIR *dir = opendir("/proc/self/fd");
    if (!dir)
        return -1;
    while (readdir(dir))
        count++;
    closedir(dir);
    return count;
}

/* ---------------- Execute Tester ---------------- */
char *run_cmd(const char *cmd)
{
    FILE *fp;
    char buffer[1024];
    char *output = NULL;
    size_t total = 0;

    fp = popen(cmd, "r");
    if (!fp)
        return NULL;

    while (fgets(buffer, sizeof(buffer), fp))
    {
        size_t len = strlen(buffer);
        output = realloc(output, total + len + 1);
        memcpy(output + total, buffer, len);
        total += len;
        output[total] = '\0';
    }
    pclose(fp);
    return output;
}

void check_exec(const char *desc, const char *cmd, const char *expected)
{
    printf("---- %s ----\n", desc);
    char *out = run_cmd(cmd);
    if (!out)
    {
        printf("❌ could not run %s\n", cmd);
        return;
    }
    if (strstr(out, expected))
        printf("✅ PASS (found '%s')\n", expected);
    else
        printf("❌ FAIL (got: %s)\n", out);
    free(out);
}

/* ---------------- FD Leak Tester ---------------- */
void check_fd_leak(const char *desc, char **cmds[])
{
    printf("---- %s ----\n", desc);

    int before = count_open_fds();
    if (before < 0)
    {
        printf("❌ could not count fds (Linux /proc needed)\n");
        return;
    }

    int ret = picoshell(cmds);

    int after = count_open_fds();

    if (ret == 0)
        printf("✅ picoshell returned 0\n");
    else
        printf("❌ picoshell returned %d\n", ret);

    if (before == after)
        printf("✅ No FD leaks (before=%d, after=%d)\n", before, after);
    else
        printf("❌ FD leak detected! before=%d after=%d\n", before, after);
}

/* ---------------- main ---------------- */
int main(void)
{
    /* Bölüm 1: execute testleri (sınav tarzı) */
    check_exec("Exec Test 1", "./picoshell /bin/ls \"|\" /usr/bin/grep picoshell", "picoshell");
    check_exec("Exec Test 2", "./picoshell echo squalala \"|\" cat \"|\" sed s/a/b/g", "squblblb");

    /* Bölüm 2: fonksiyon + fd leak testleri */
    char *cmd1[] = {"echo", "hello", NULL};
    char *cmd2[] = {"cat", NULL};
    char **pipeline1[] = {cmd1, cmd2, NULL};

    check_fd_leak("FD Leak Test (echo | cat)", pipeline1);

    return 0;
}
