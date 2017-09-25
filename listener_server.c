/* A simple server (listener) in the internet domain using TCP
   The port number is passed as an argument
   This version runs forever, forking off a separate 
   process for each connection
   
   it will be called in the terminal as ./listener_server.c 1025*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void dostuff(int); 
//This function is called when a system call fails. It displays a message about the error on stderr and then aborts the program.
void error(char *msg)
{
    perror("Sorry, the system call failed");//You either let it as perror(msg) and it will print the standard error message, or you can personalize it like I did. It still prints the standard message right next to mine.
    exit(1);
}

int main(int argc, char *argv[])
{
    /*sockfd and newsockfd are file descriptor, array subscripts into the file descriptor table. They store the values returned by the socket system call and the accept system call.
    Each running process has a file descriptor table which contains pointers to all open i/o streams.  When a process starts, three entries are created in the first three cells of the table.
    Entry 0 points to standard input, entry 1 points to standard output, and entry 2 points to standard error. Whenever a file is opened, a new entry is created in this table, usually in the first available empty slot. The socket system call returns an entry into this table; i.e. a small integer.  This value is used for other calls which use this socket.  The accept system call returns another entry into this table.  The value returned by accept is used for reading and writing to that connection.
    portno - stores the port number on which the server accepts connections
    clilen - stores the size of the address of the client. It is needed for the accept system call.*/
     int sockfd, newsockfd, portno, clilen, pid;
       
     
     /*sockaddr_in - a structure containing an internet address. it is defined in netinet/in.h
     serv_addr - contains the address of the server
     cli_addr - contains the address of te client which connects to the server */
     struct sockaddr_in serv_addr, cli_addr;
     

     //it checks wheter the executable was called with the correct number of arguments. if not, it exits itself.
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     
     /*the socket() function creates a new socket.
      AF_INET is the address domain of the socket (INET = through Internet)
      SOCK_STREAM - the type of the socket (TCP in our case)
      0 - lets th esystem to decide whether the protocol used is TCP or UDP
      sockfd - stores a number into the descriptor table and it is later used.
      it return -1 if it finds any errors.*/
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     
     //if sockfd is -1 it means it found any errors which will be displayed.*/
     if (sockfd < 0) 
        error("ERROR opening socket");
     
     //sets all values in a buffer to 0. it initializes serv_addr to zeros
     memset(&serv_addr, 0,  sizeof(serv_addr));
     
     //atoi() converts the arguments passed in in the terminal from a string of digits to an int
     portno = atoi(argv[1]);
     
     //standard values which have to be set like this
     serv_addr.sin_family = AF_INET;
     
     //This field contains the IP address of the host. For server code, this will always be the IP address of the machine on which the server is running, and there is a symbolic constant INADDR_ANY which gets this address.
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     
     //htons() converts a port number in host byte order to a port number in network byte order - a thing that has to be in my code, for multi-platform peace and happiness
     serv_addr.sin_port = htons(portno);
     
     /*it binds a socket to the address of the current host and port number on which the server will run.
     It takes three arguments, the socket file descriptor, the address to which is bound, and the size of the address to which it is bound. The second argument is a pointer to a structure of type sockaddr, but what is passed in is a structure of type sockaddr_in, and so this must be cast to the correct type. */
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     
     /*The listen system call allows the process to listen on the socket for connections. The first argument is the socket file descriptor, and the second is the size of the backlog queue, i.e., the number of connections that can be waiting while the process is handling a particular connection. This should be set to 5, the maximum size permitted by most systems. If the first argument is a valid socket, this call cannot fail, and so the code doesn't check for errors.*/
     listen(sockfd, 5);
     
     clilen = sizeof(cli_addr);//gets the length in bytes of the client address
     
     while(1) {
     /*The accept() system call causes the process to block until a client connects to the server. Thus, it wakes up the process when a connection from a client has been successfully established. It returns a new file descriptor, and all communication on this connection should be done using the new file descriptor. The second argument is a reference pointer to the address of the client on the other end of the connection, and the third argument is the size of this structure.*/
        newsockfd = accept(sockfd, (struct sockaddr *)  &cli_addr, &clilen);
     
        if (newsockfd < 0) 
            error("ERROR on accept");
        
        pid = fork();
        
        if (pid < 0) {
            error("Error on accept");
        }
        if (pid == 0) {
            dostuff(newsockfd);
            close(sockfd);
            exit(0);
        } else close(newsockfd);
     }
     
     return 0;
}

/*there is a separate instance of this function for each connection. it handles all communication once a connection has been established*/
        
void dostuff(int sock) {
    
    char buffer[256];//the server reads characters from the socket connection into this buffer
     
    int n; //the return value for read() and write(), it contains the number of chars read or written
    
    //we will get to this point only after a client has successfully connected to our server
    memset(buffer, 0, 256);
    
    //it read from the client file descriptor, the one returned by accept()
     n = read(sock, &buffer, 255); //by default it reads 255 characters from the mesage
     
     if (n < 0) 
         error("ERROR reading from socket");
     
     printf("Here is the message: %s\n", buffer);
     
     /*Once a connection has been established, both ends can both read and write to the connection. Naturally, everything written by the client will be read by the server, and everything written by the server will be read by the client. This code simply writes a short message to the client. The last argument of write is the size of the message.*/
     n = write(sock, "I got your message", 18);
     
     if (n < 0) 
         error("ERROR writing to socket");
     
}
