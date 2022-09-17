#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
int main()
{
    int port;
    char message[50];
    struct sockaddr_in serveraddr;
    socklen_t len;
    int clientsocket=socket(AF_INET,SOCK_STREAM);
    printf("Enter the Port Number");
    scanf("%d",&port);
    bzero((char*)&serveraddr,sizeof(serveraddr));
    
    serveraddr.sin_port=htons(port);
    serveraddr.sin_family=AF_INET;
    connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    send(clientsocket,"Hey There",sizeof("Hey There"));
    recv(clientsocket,message,sizeof(message));
    close(clientsocket);
    return 0;
}