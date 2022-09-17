#include<stdio.h>
#include<stdlib.h>
int main()
{
    int buck_size,store=0,incoming,outgoing,n;
    printf("Enter the Bucket Size, Outgoing Rate,no of inputs");
    scanf("%d %d %d",&buck_size,&outgoing,&n);
    while(n!=0)
    {
        printf("Enter the Incoming packet size");
        scanf("%d",&incoming);
        printf("\n Incoming Packet Size %d",incoming);
        if(incoming<=(buck_size-store))
        {
            store+=incoming;
            printf("\n Buffer Bucket Size %d out of %d",store,buck_size);
        }
        else{
            store=buck_size;
            printf("\n Dropped packets %d",incoming-(buck_size-store));
            printf("\n Buffer Bucket Size %d out of %d",store,buck_size);
        }
        
        store=store-outgoing;
        printf("Buffer Bucket Size %d out of %d",store,buck_size);
        n--;
    }

    return 0;
}