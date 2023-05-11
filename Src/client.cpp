#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <cstring>

#define SOCKET_PATH "UUI-SERVER"


int main(int argc, char* argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_un address;
    const char* message = "Hello, Reader! ";

    char messageRecieved[100];

    // Create a socket
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    // Set the address
    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, SOCKET_PATH);

    // Connect to the socket
    connect(sockfd, (struct sockaddr*)&address, sizeof(address));

    // Write the message to the socket
    write(sockfd, argv[1], strlen(argv[1]) + 1);
    close(sockfd);

    // Listen for connections
    listen(sockfd, 5);

    // Accept a connection
    newsockfd = accept(sockfd, NULL, NULL);

    // Read the message from the socket
    read(newsockfd, messageRecieved, sizeof(messageRecieved));
    std::cout << "Received message: " << messageRecieved << std::endl;

    // Clean up
    close(newsockfd);

    return 0;
}