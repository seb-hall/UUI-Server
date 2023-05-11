#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <cstring>

#define SOCKET_PATH "UUI-SERVER"

const char* messageSent = "Thank uou for your message.\n";

int main() {
    int sockfd, newsockfd;
    struct sockaddr_un address;
    char message[100];

    // Create a socket
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    // Set the address
    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, SOCKET_PATH);

    // Bind the socket to the address
    bind(sockfd, (struct sockaddr*)&address, sizeof(address));


    while (true) {
    // Listen for connections
        listen(sockfd, 5);

        // Accept a connection
        newsockfd = accept(sockfd, NULL, NULL);

        // Read the message from the socket
        read(newsockfd, message, sizeof(message));
        std::cout << "Received message: " << message << std::endl;

        // Clean up
        close(newsockfd);



        // Connect to the socket
        //connect(sockfd, (struct sockaddr*)&address, sizeof(address));

        // Write the message to the socket
        write(sockfd, messageSent, strlen(messageSent) + 1);
        //close(sockfd);
    }
    
    close(sockfd);
    unlink(SOCKET_PATH);

    return 0;
}

