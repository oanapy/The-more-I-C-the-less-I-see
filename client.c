/*pretty similar to the listener(server), with almost the same variables
 
 it will be called in the terminal as ./client localhost 1025 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(char *msg)
{
    perror(msg);
    exit(0);
}

void main(int argc, char *argv[])
{
    int sockfd, portno, n;

    struct sockaddr_in serv_addr; //The variable serv_addr will contain the address of the server to which we want to connect. It is of type struct sockaddr_in.
    struct hostent *server;//The variable server is a pointer to a structure of type hostent.

    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    puts("Socket created!\n");
    
    if (sockfd < 0) 
        error("ERROR opening socket");
    
    server = gethostbyname(argv[1]);//argv[1] contains the name of a host on the Internet, e.g. cheerios@cs.rpi.edu.
    
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    
    /*The connect function is called by the client to establish a connection to the server. It takes three arguments, the socket file descriptor, the address of the host to which it wants to connect (including the port number), and the size of this address. This function returns 0 on success and -1 if it fails. */
    if (connect(sockfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }
    puts("Connected\n");
    
    while(1){
    /*The remaining code should be fairly clear. It prompts the user to enter a message, uses fgets to read the message from stdin, writes the message to the socket, reads the reply from the socket, and displays this reply on the screen.*/
        printf("Please enter the message: ");
        memset(buffer, 0, 256);
        fgets(buffer, 255, stdin);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) { 
            error("ERROR writing to socket");
        }
        memset(buffer, 0, 256);
    
        n = read(sockfd, buffer, 255);
    
        if (n < 0) {
            error("ERROR reading from socket");
        }
    
        printf("%s\n", buffer);
    }
        close(sockfd);
    }
