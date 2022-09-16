#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
int main()
{
    FILE *fp;
    int csd,n,ser,s,cli,cport,newsd;
    char name[100],rcvmsg[100],rcvg[100],fname[100];
    struct sockaddr_in serveraddr;
    printf("\n Enter the Port Number");
    scanf("%d",&port);
    csd=socket(AF_INET,SOCK_STREAM,0);
    if(csd<0)
    {
        printf("\n Error");
    }
    else{
        printf("\n Socket is created");
    }
    serveraddr.sin_port=htons(port);
    serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
    serveraddr.sin_family=AF_INET;
    if(connect(csd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0){
        printf("Error in Connection\n");
    }
    else{
        printf("\n Existing File Name\t");
        scanf("%s",&name);
        printf("\n Enter the new file Name")
        scanf("%s",&fname);
        fp=fopen(fname,"w");
        send(csd,name,sizeof(name),0);
        while(1)
        {
            s=recv(csd,rcvg,100,0);
            rcvg[s]='\0';
            if(strcmp(rcvg,"error")==0)
            {
                printf("File is Transfered...\n");
                fclose(fp);
                close(csd);
                break;
            }
            else{
                puts(rcvg,stdout);
                fprintf(fp,"%s",rcvg);
                
            }
        }
    }
    return 0;
}