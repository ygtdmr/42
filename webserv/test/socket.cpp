#include <iostream>
#include <sys/types.h>
#include <sys/socket.h> // socket, bind, listen, accept, setsockopt
#include <netinet/in.h> // struct sockaddr_in, htons
#include <unistd.h>     // close, read, write
#include <string.h>     // strerror
#include <errno.h>      // errno
#include <stdlib.h>     // exit


int main( void )
{
	// 1. Soket Oluşturma
	//	IPv4 (AF_INET) ve TCP (SOCK_STREAM)
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Soket olusturulamadi: " << strerror(errno) << std::endl;
        return 1;
    }
    std::cout << "1. Soket basariyla olusturuldu. FD: " << server_fd << std::endl;


	// 2. Adres Yapısını Hazırlama
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address)); // İçini sıfırla
    
    address.sin_family = AF_INET;         // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // Bilgisayardaki tüm ağ arayüzlerini dinle (localhost dahil)
    address.sin_port = htons(80);       // 80 portunu dinle (Network Byte Order'a çevirdik)

	// 3. Bind (Bağlama) İşlemi
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Bind hatasi: " << strerror(errno) << std::endl;
        close(server_fd);
        return 1;
    }
    std::cout << "2. Soket 80 portuna basariyla baglandi." << std::endl;

	// 4. Listen (Dinleme) Modu
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen hatasi: " << strerror(errno) << std::endl;
        close(server_fd);
        return 1;
    }
    std::cout << "3. Sunucu dinliyor... Port: 80" << std::endl;

	// 5. Accept (Bağlantıyı Kabul Etme)
    struct sockaddr_in client_address;
    socklen_t addr_len = sizeof(client_address);
    
    std::cout << "Baglanti bekleniyor..." << std::endl;
    int client_fd = accept(server_fd, (struct sockaddr*)&client_address, &addr_len);
    if (client_fd < 0) {
        std::cerr << "Accept hatasi: " << strerror(errno) << std::endl;
        close(server_fd);
        return 1;
    }
    std::cout << "4. Bir istemci baglandi! Yeni FD: " << client_fd << std::endl;
	

	// 6. Mesaj Gönderme
    const char *mesaj = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 17\r\n\r\nMerhaba, Soket!\n";
    write(client_fd, mesaj, strlen(mesaj));
    std::cout << "5. Mesaj gonderildi." << std::endl;

    // 7. Kapatma işlemleri
    close(client_fd); // İstemciyle işimiz bitti
    close(server_fd); // Sunucuyu kapatıyoruz
    std::cout << "6. Soketler kapatildi. Program sonlandirildi." << std::endl;

	return (0);
}
