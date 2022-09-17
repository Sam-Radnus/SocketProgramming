#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<netdb.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    int port,serversocket,clientsocket;
    struct sockaddr_in serveraddr,clientaddr;
    char message[50];
    printf("Enter the Port Number");
    scanf("%d",&port);
    serversocket=socket(AF_INET,SOCK_STREAM,0);
    bzero((char*)&serveraddr,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(port);
    serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
   

    bind(serversocket(struct sockaddr *)&serveraddr,sizeof(serveraddr));

    bzero((char*)&clientaddr,sizeof(clientaddr));
    listen(serversocket,5);

    clientsocket=accept(serversocket,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
    read(clientsocket,message,sizeof(message));
    write(clientsocket,"Hey There",sizeof("Hey There"));
    close(clientsocket);
    close(serversocket);
    return 0;
}