#include<stdio.h>
#include<stdlib.h>

struct sjf{
    char process;
    int arr_time,ser_time;
    int start_time,finish_time;

};

void sort(struct sjf *a,int x);

int main()
{
    int n;
    printf("How many processes? Must be greater than 1\n");
    scanf("%d",&n);
    fflush(stdin);
    struct sjf p[n];
    int i;
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        scanf("%c %d %d",&p[i].process,&p[i].arr_time,&p[i].ser_time);



        //p[i].ser_time=p[i].finish_time-p[i].start_time;
        //if(p[i].ser_time<0)
        //{
        //    printf("Wrong Input!!!\n");
        //    i--;
        //}

    }
    printf("Before FCFS\n");
    printf("Process \tArrival_Time \tService_Time \n");
    for(i=0;i<n;i++)
    {

        printf("%8c %14d %14d\n",p[i].process,p[i].arr_time,p[i].ser_time);
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
    printf("After FCFS\n");
    printf("Process \tArrival_Time \tService_Time \tStart_time \tFinish_time \tFinish_time\n");
    for(i=0;i<n;i++)
    {

        printf("%8c %14d %14d %14d %14d\n",p[i].process,p[i].arr_time,p[i].ser_time,p[i].start_time,p[i].finish_time);
    }

    return 0;
}
void sort(struct sjf *a,int x)
{
    int i,j;
    struct sjf temp;
    for(i=x-1;i>=0;i--)
    {
        for(j=0;j<=i-1;j++)
        {
            if(a[j].ser_time>a[j+1].ser_time)
               {
                   temp=a[j+1];
                   a[j+1]=a[j];
                   a[j]=temp;
               }
        }
    }
}
