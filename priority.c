#include<stdio.h>
#include<stdlib.h>

struct pr{
    char process;
    int ser_time,priority;
    int start_time,finish_time;

};

void sort(struct pr *a,int x);

int main()
{
    int n;
    printf("How many processes?\n");
    scanf("%d",&n);
    fflush(stdin);
    struct pr p[n];
    int i;
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        scanf("%c %d %d",&p[i].process,&p[i].ser_time,&p[i].priority);
    }
    printf("Before PR\n");
    printf("Process \tService_Time \tPriority\n");
    for(i=0;i<n;i++)
    {

        printf("%8c  %14d %14d\n",p[i].process,p[i].ser_time,p[i].priority);
    }

    sort(p,n);
    int strt=0;
    for(i=0;i<n;i++)
    {
        p[i].start_time=strt;
        p[i].finish_time=strt+p[i].ser_time;
        strt=p[i].finish_time;
        //p[i].turnaround=p[i].finish_time-p[i].arr_time;
    }
    printf("After PR\n");
    printf("Process \tService_Time \tStart_time \tFinish_time \n");
    float tt=0;
    for(i=0;i<n;i++)
    {

        printf("%8c %14d %14d %14d \n",p[i].process,p[i].ser_time,p[i].start_time,p[i].finish_time);
        tt=tt+p[i].start_time;
    }

    printf("Average Wait Time = %f\n",tt/n);

    printf("Grand Chart::::::::::::::::::::::::::::\n");
    printf("%2s","");
    for(i=0;i<n;i++)
    {
        printf("%4c",p[i].process);
    }
    puts("");
    for(i=0;i<n;i++)
    {
        printf("%4d",p[i].start_time);//,p[i].process);
    }
    printf("   %d",p[i-1].finish_time);

    return 0;
}
void sort(struct pr *a,int x)
{
    int i,j;
    struct pr temp;
    for(i=x-1;i>=0;i--)
    {
        for(j=0;j<=i-1;j++)
        {
            if(a[j].priority>a[j+1].priority)
               {
                   temp=a[j+1];
                   a[j+1]=a[j];
                   a[j]=temp;
               }
        }
    }
}
