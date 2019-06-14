#include<stdio.h>
#include<stdlib.h>

struct prcs{
    char process;
    int arr_time,ser_time,start_time,finish_time;
    int wt,priority;

};
void fcfs(struct prcs *a,int x);
void prt(struct prcs *a,int x);


int main()
{
    int n,fcount=0,scount=0;
    printf("How many processes?\n");
    scanf("%d",&n);
    struct prcs f[n],s[n];
    int i;
    printf("Process \tService_Time \tArrival_Time\tPriority\n");
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        scanf("%c %d %d %d",&f[i].process,&f[i].ser_time,&f[i].arr_time,&f[i].priority);
        s[i]=f[i];
    }
    fcfs(f,n);
    prt(s,n);
    int strtf=f[0].arr_time,strts=0;
    float twtf=0,twts=0;
    for(i=0;i<n;i++)
    {
        if(f[i].arr_time>f[i-1].finish_time)
        {
            strtf=f[i].arr_time;
        }
        f[i].start_time=strtf;
        f[i].finish_time=strtf+f[i].ser_time;
        strtf=f[i].finish_time;
        f[i].wt=f[i].start_time-f[i].arr_time;
        twtf=twtf+f[i].wt;

        s[i].start_time=strts;
        s[i].finish_time=strts+s[i].ser_time;
        strts=s[i].finish_time;
        s[i].wt=s[i].start_time;
        twts=twts+s[i].wt;
    }
    if(twtf>twts)
    {
        scount++;
    }
    else if(twtf<twts)
    {
        fcount++;
    }
    if(f[n-1].finish_time>s[n-1].finish_time)
    {
        scount++;
    }
    else if(s[n-1].finish_time>f[n-1].finish_time)
    {
        fcount++;
    }
    printf("After FCFS\n");
    printf("Process Arrival_Time Service_Time Start_time Finish_time \n");
    for(i=0;i<n;i++)
    {
        printf("%4c %8d %12d %12d %12d\n",f[i].process,f[i].arr_time,f[i].ser_time,f[i].start_time,f[i].finish_time);
    }
    printf("After prt\n");
    printf("Process \tService_Time \tStart_time \tFinish_time\n");
    float tt;
    for(i=0;i<n;i++)
    {
        printf("%8c %14d %14d %14d\n",s[i].process,s[i].ser_time,s[i].start_time,s[i].finish_time);
    }
    puts("\n\nComparison 1: Grandchart:\n");
    printf("FCFS:\n");
    printf("%2s","");
    for(i=0;i<n;i++)
    {
        printf("%4c",f[i].process);
    }
    puts("");
    for(i=0;i<n;i++)
    {
        printf("%4d",f[i].start_time);//,p[i].process);
    }
    printf("   %d",f[n-1].finish_time);
    printf("\n\PRT:\n");
    printf("%2s","");
    for(i=0;i<n;i++)
    {
        printf("%4c",s[i].process);
    }
    puts("");
    for(i=0;i<n;i++)
    {
        printf("%4d",s[i].start_time);//,p[i].process);
    }
    printf("   %d",s[n-1].finish_time);
    puts("\n\nComparison 2: Total Wait time and Average Wait time:");
    printf("FCFS------> %.0f and %.2f\n",twtf,twtf/n);
    printf("\nPRT------> %.0f and %.2f\n",twts,twts/n);

    puts("\n\nComparison 3: Total time for all the processes to Execute:");
    printf("FCFS------> %.0f\n",f[n-1].finish_time);
    printf("\nPRT-------> %.0f\n",s[n-1].finish_time);

    if(scount>fcount)
    {
        puts("PRT is the more Efficient algorithm");
    }
    else if(scount<fcount)
    {
        puts("FCFS is the more Efficient algorithm");
    }
    else
    {
        puts("Both FCFS and PRT is equally efficient for these set of processes");
    }
    return 0;
}

void fcfs(struct prcs *a,int x)
{
    int i,j;
    struct prcs temp;
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

void prt(struct prcs *a,int x)
{
    int i,j;
    struct prcs temp;
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



