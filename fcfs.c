#include<stdio.h>
#include<stdlib.h>

struct fcfs{
    char process;
    int arr_time,ser_time,start_time,finish_time;

};

void sort(struct fcfs *a,int x);

int main()
{
    int n;
    printf("How many processes?\n");
    scanf("%d",&n);
    struct fcfs p[n];
    int i;
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        scanf("%c %d %d",&p[i].process,&p[i].arr_time,&p[i].ser_time);


    }
    printf("Before FCFS\n");
    printf("Process \tArrival_Time \tService_Time \n");
    for(i=0;i<n;i++)
    {

        printf("%8c %14d %14d\n",p[i].process,p[i].arr_time,p[i].ser_time);
    }

    sort(p,n);
    int strt=p[0].arr_time;
    for(i=0;i<n;i++)
    {
        if(p[i].arr_time>p[i-1].finish_time)
        {
            strt=p[i].arr_time;
        }
        p[i].start_time=strt;
        p[i].finish_time=strt+p[i].ser_time;
        strt=p[i].finish_time;

    }
    printf("After FCFS\n");
    printf("Process \tArrival_Time \tService_Time \tStart_time \tFinish_time \n");
    for(i=0;i<n;i++)
    {

        printf("%8c %14d %14d %14d %14d\n",p[i].process,p[i].arr_time,p[i].ser_time,p[i].start_time,p[i].finish_time);
    }

    return 0;
}

void sort(struct fcfs *a,int x)
{
    int i,j;
    struct fcfs temp;
    for(i=x-1;i>=0;i--)
    {
        for(j=0;j<=i-1;j++)
        {
            if(a[j].arr_time>a[j+1].arr_time)
               {
                   temp=a[j+1];
                   a[j+1]=a[j];
                   a[j]=temp;
               }
        }
    }
}

