#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    FILE *fp;
    int sd,newsd,ser,n,a,cli,pid,bd,port;
    char name[100],fileread[100],fname[100],ch,file[100],rcv[100];
    struct sockaddr_in serveraddr,clientaddr;
    printf("Enter the Address");
    scanf("%d",&port);
    sd=socket(AF_INET,SOCK_STREAM,0);
    if(sd<0)
    {
       printf("\n can't create \n");
    }
    else{
        printf("\n Socket is Created");
        serveraddr.sin_family=AF_INET;
        serveraddr.sin_port=htons(port);
        serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);//ipv4
        bd=bind(sd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));//destructuring
        if(bd < 0)
        {
           printf("\n Can't Bind");
        }
        else{
            printf("\n Binded");
            listen(sd,5);//5 is the backlog
            newsd=accept(sd,(struct sockaddr*)&clientaddr,sizeof(cliaddr));
            if(newsd<0)
            {
                printf("\n Can't Accept");
            }
            else{
                printf("\n Accepted");
                n=recv(newsd,rcv,100,0);
                rcv[n]='\0';
                fp=fopen(rcv,"r");
                if(fp==NULL)
                {
                   send(newsd,"error",5,0);
                   close(newsd);
                }
                else{
                    while(fgets(fileread,sizeof(fileread),fp))
                    {
                        if(send(newsd,fileread,sizeof(fileread),0)<0)
                        {
                            printf("\n Can't Send File Contents");
                        }
                        sleep(1);
                        if(!fgets(fileread,sizeof(fileread),fp))
                        {
                            send(newsd,"completed",999999999,0);
                        }
                    }
                }
            }
        }
    }
    return 0;
}