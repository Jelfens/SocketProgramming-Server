#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define PORT 80
#define BUFFER_SIZE 1024
#define SERVER_ADDR "127.0.0.1"

int main(int argc, char* argv[]) {
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char* buffer;

    printf("\nInitialising Winsock...");

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed. Error Code : %d", WSAGetLastError());
        return 1;
    }

    printf("Initialised. \n");

    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d", WSAGetLastError());
    }

    printf("Socket created.\n");

    server.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (bind(s, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        puts("connect error");
        return 1;
    }

    puts("Binded");

    if (listen(s, 5) == SOCKET_ERROR)
    {
        printf("Failed to listen on socket.\n");
        return 1;
    }

    puts("Listening");

    printf("Waiting for connection on port %d...\n", PORT);
    SOCKET client_socket = accept(s, NULL, NULL);
    if (client_socket == INVALID_SOCKET)
    {
        printf("Failed to accept connection.\n");
        return 1;
    }
    //BURDAN DEVAM
    //// �leti�im kurulur
    //char buffer[BUFFER_SIZE];
    //while (1)
    //{
    //    // Veri al�n�r
    //    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    //    if (bytes_received <= 0)
    //        break;


    //    // Veri ekrana yazd�r�l�r
    //    buffer[bytes_received] = '\0';
    //    printf("Received: %s\n", buffer);

    //    // Veri g�nderilir
    //    printf("Enter message to send: ");
    //    gets(buffer);
    //    int bytes_sent = send(client_socket, buffer, strlen(buffer), 0);
    //    if (bytes_sent <= 0)
    //        break;
    //}

    //// Soketler kapat�l�r
    //closesocket(client_socket);
    //closesocket(listen_socket);

    //// Winsock kapat�l�r
    //WSACleanup();

    //printf("Mesajı girin");
    //scanf_s("%s",buffer,BUFFER_SIZE);
    //if(sizeof(buffer)>0)
    //if (send(s, buffer, BUFFER_SIZE, 0) < 0) {
    //    puts("Send failed");
    //    return 1;
    //}
    //puts("Data Send\n");

    //memset(buffer, 0, BUFFER_SIZE);

    //if (recv(s, buffer, BUFFER_SIZE, 0) == SOCKET_ERROR) {
    //    puts("recv failed\n;");
    //}

    //puts("Reply received\n");

    //puts(buffer);

    return 0;
}