#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <ctype.h>

#include "../ft_isalpha.c"
#include "../ft_isdigit.c"
#include "../ft_isalnum.c"
#include "../ft_isascii.c"
#include "../ft_isprint.c"
#include "../ft_strlen.c"
#include "../ft_memset.c"

int	main()
{
	wchar_t c;
	char	*s;

	c = 'a';
	printf("RESULT [ft_isalpha] test input is: [%c], result is (ft) [%d] result is (org) [%d] expected [1]\n", c, ft_isalpha(c), isalpha(c));
	c = '2';
	printf("RESULT [ft_isalpha] test input is: [%c], result is (ft) [%d] result is (org) [%d] expected [0]\n", c, ft_isalpha(c), isalpha(c));

	printf("\n");
	
	c = '2';
	printf("RESULT [ft_isdigit] test input is: [%c], result is (ft) [%d] result is (org) [%d] expected [1]\n", c, ft_isdigit(c), isdigit(c));
	c = 'a';
	printf("RESULT [ft_isdigit] test input is: [%c], result is (ft) [%d] result is (org) [%d] expected [0]\n", c, ft_isdigit(c), isdigit(c));

	printf("\n");

	c = 'a';
	printf("RESULT [ft_isalnum] test input is: [%c], result is (ft) [%d] result is (org) [%d] expected [1]\n", c, ft_isalnum(c), isalnum(c));
	c = '2';
	printf("RESULT [ft_isalnum] test input is: [%c], result is (ft) [%d] result is (org) [%d] expected [1]\n", c, ft_isalnum(c), isalnum(c));
	c = '/';
	printf("RESULT [ft_isalnum] test input is: [%c], result is (ft) [%d] result is (org) [%d] expected [0]\n", c, ft_isalnum(c), isalnum(c));

	printf("\n");

	c = '&';
	printf("RESULT [ft_isascii] test input is: [%c], result is (ft) [%d] result is (org) [%d] expected [1]\n", c, ft_isascii(c), isascii(c));
	c = L'₺';
	printf("RESULT [ft_isascii] test input is: [%c], result is (ft) [%d] result is (org) [%d] expected [0]\n", c, ft_isascii(c), isascii(c));

	printf("\n");

	c = L' ';
	printf("RESULT [ft_isprint] test input is: [%c], result is (ft) [%d] result is (org) [%d] expected [1]\n", c, ft_isprint(c), isprint(c));
	c = L'\t';
	printf("RESULT [ft_isprint] test input is: [%c], result is (ft) [%d] result is (org) [%d] expected [0]\n", c, ft_isprint(c), isprint(c));

	printf("\n");

	s = "";
	printf("RESULT [ft_strlen] test input is: [%s], result is (ft) [%lu] result is (org) [%lu] expected [0]\n", s, ft_strlen(s), strlen(s));
	s = "Hello World";
	printf("RESULT [ft_strlen] test input is: [%s], result is (ft) [%lu] result is (org) [%lu] expected [11]\n", s, ft_strlen(s), strlen(s));


	// CHECK THIS ISSUE.

	s = "HELLO WORLD";
	printf("RESULT [ft_memset] test input is: [%s], ", s);
	memset(s, 'A', 3);
	//printf("result is (ft) [%s] ", s);
	//s = "HELLO WORLD";
	//memset(s, 0, ft_strlen(s));
	//printf("result is (org) [%s] expected [NULL]", s);
	return 0;
}