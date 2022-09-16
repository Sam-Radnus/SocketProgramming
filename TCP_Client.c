#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>
int main()
{
    int clientsocket,port;
    struct sockaddr_in serveraddr;
    socklen_t len;
    char message[50];
    
    clientsocket=socket(AF_INET,SOCK_STREAM);
    bzero((char*)&serveraddr,sizeof(serveraddr));
    len=sizeof(serveraddr);
    
    serveraddr.sin_family=AF_INET;
    printf("Enter the Port Number");
    scanf("%d",&port);
    serveraddr.sin_port=htons(port);
    
    connect(clientsocket(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    
    send(clientsocket,"Hey There",sizeof("Hey There"));
    recv(clientsocket,message,sizeof(message));
    
    close(clientsocket);

    return 0;
}