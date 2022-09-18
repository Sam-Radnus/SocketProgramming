#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
function send(int socket,char str[],struct sockaddr,struct client)
{
    if(sendto(socket,str,sizeof(str)),0,(struct sockaddr *)&client,sizeof(client)<0)
   {
     printf("Error in Sending Message");
   }
}
function recv(int socket,char str[],struct sockaddr,struct client)
{
   if(recvfrom(socket,str,sizeof(str)),0,(struct sockaddr *)&client,sizeof(client)<0)
   {
     printf("Error in Message");
   }
}
int main(int argc,char* argv[])
{
   struct sockaddr_in server,client;
   char str[50],msg[50];
   if(argc!=2){
     printf("Input form Incorrect");
   }
   int socket=socket(AF_INET,SOCK_DGRAM,0);
   if(socket==-1)
    {
     printf("Error in socket()");
    }
   server.sin_family=AF_INET;
   server.sin_addr=htonl(INADDR_ANY);
   server.sin_port=htons(atoi(argv[1]));

   client.sin_family=AF_INET;
   client.sin_addr=htonl(INADDR_ANY);
   client.sin_port=htons(atoi(argv[1]));
   
   if(bind(socket,(struct sockaddr *)&server,sizeof(server))<0)
   {
    printf("Error in Bind()");
   }
   sleep(3);
   
   recv(socket,str,sockaddr,client);
   printf("\n Got Message from Client:%s",str);
   printf("\n Sending Message To Client");
   
   strcpy(str,"220 127.0.0.1");
   sleep(10);

   send(socket,str,sockaddr,client);
   printf("Error in recv");

   if(strncmp(str,"HELLO",4)){
    printf("\n Hello Expected from client");
   }

   printf("\n %s",str);
   printf("\n Sending Response");
   strcpy(str,"250 ok");
   send(socket,str,sockaddr,client);

   sleep(3);
   recv(socket,str,sockaddr,client);
   if(strncmp(str,"RCPT to",7))
   {
    printf("\n RCPT TO expected from client");
   }
   printf("\n %s",str);
   printf("\n Sending Response");
   strcpy(str,"250 OK");

   send(socket,str,sockaddr,client);
   recv(socket,str,sockaddr,client);

   printf("Mail Body Received");
   printf("%s",msg);
   recv();
   if(strncmp(str,"QUIT",4))
   {
     printf("QUIT expected from client");
   }
   printf("Sending Quit");
   strcpy(str,"221 OK");
   
   send(socket,str,sockaddr,client);
   close(socket);
   return 0;



}
