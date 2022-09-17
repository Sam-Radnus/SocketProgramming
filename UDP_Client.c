#include<netinet/in.h>
#include<netdb.h>
#include<strings.h>
int main(){
    int clientsocket,port;
    struct sockaddr_in serveraddr;
    socklen_t len;
    char message[50];
    bzero((char*)&serveraddr,sizeof(serveraddr));
    printf("Enter port #");
    scanf("%d",&port);
    clientsocket=socket(AF_INET,SOCK_DGRAM,0);
    serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(port);
    fgets(message,2,stdin);
    printf("\n Sending Message for Server connection");
    sendto(clientsocket,"Message",sizeof("Message"),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    printf("\n Receiving Message from Server");
    recvfrom(clientsocket,message,sizeof(message),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    printf("\n Message received :\t%s\n",messsage);
    close(clientsocket);
    return 0;
}
