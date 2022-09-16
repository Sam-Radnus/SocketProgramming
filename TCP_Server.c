#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netdb.h>
int main()
{
    int serversocket,clientsocket,port;
    struct sockaddr_in serveraddr,clientaddr;
    socklen_t len;//type of integer
    char message[50];
    struct serveraddr;

    serversocket=socket(AF_INET,SOCK_STREAM,0)//defining the server socket
    //AF_INET:-address format , SOCK_STREAM:-TCP 
    bzero((char*)&serveraddr,sizeof(serveraddr));//erasing the memory area
    serveraddr.sin_family=AF_INET;
    
    printf("Enter the Port Number");
    scanf("%d",&port);
    
    serveraddr.sin_port=htons(port);// translates a short integer from host byte order to network byte order.
    serveraddr.sin_addr.s_addr=INADDR_ANY //Special IP Address

    bind(serversocket(struct socketaddr*)&serveraddr,sizeof(serveraddr));
    

    bzero((char*)&clientaddr,sizeof(clientaddr));
    len=sizeof(clientaddr);
    listen(serversocket,5);//It puts the server socket in a passive mode, where it waits for the client to approach the server to make a connection
 
    printf("\n waiting for the client connection");
    printf("\n nhai:");

    clientsocket=accept(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    printf("\n Client connectivity received");
    printf("\n Reading Message from the client");
    
    read(clientsocket,message,sizeof(message));
    printf("\n The Client has send %s",message);
    printf("\n Sending message to the client");
    
    write(clientsocket,"Your Message was Received",sizeof("your message received"));
    close(clientsocket);
    close(serversocket);
    
    return 0;
}
