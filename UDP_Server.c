#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
int main()
{
    int serversocket,port;
    struct sockaddr_in serveraddr,clientaddr;
    char message[50];
    serversocket=socket(AF_INET,SOCK_DGRAM,0);
    bzero((char*)&serveraddr,sizeof(serveraddr));
    printf("\n Enter a Port Number");
    scanf("%d",&port);
    serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
    serveraddr.sin_port=htons(port);
    serveradrr.sin_family=AF_INET;
    bind(serversocket,(struct sockadd*)&serveraddr,sizeof(serveraddr));//socket identifier
    bzero((char*)&clientaddr,sizeof(clientaddr));
    recvfrom(serversocket,message,sizeof(message),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
    printf("\n The Message Received:%d",message);
    sendto(serversocket,"Your Message was Received",sizof("Your Message was Received"),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
    close(serversocket);
    return 0;
}