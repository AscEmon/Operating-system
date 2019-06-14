#include<stdio.h>
#include<stdlib.h>

struct process{
    char process_name;
    int arr_time,s_t,start_time,finish_time,count,wt,turnaround;
};
void sjf(struct process *a,int x);
void fcfs(struct process *a,int x);
int main()
{
    int quantum,c=0;
    float wtr=0,wts=0,wtf=0;
    printf("How many Process???\n");
    int n;
    scanf("%d",&n);
    struct process rr[n],ss[n],bb[n],s[n],f[n];
    int st[n];
    int i,et=0;
    printf("Process \tService_Time \tArrival_Time\tPriority\n");
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        scanf("%c %d %d",&rr[i].process_name,&rr[i].s_t,&rr[i].arr_time);
        st[i]=rr[i].s_t;
        rr[i].count=0;
        ss[i]=rr[i];
        bb[i]=rr[i];
        s[i]=rr[i];
        f[i]=rr[i];
    }
    printf("Enter quantum \n");
    scanf("%d",&quantum);
    sjf(s,n);
    fcfs(f,n);
    int strtf=0,strts=0;
    for(i=0;i<n;i++)
    {
        if(f[i].arr_time>f[i-1].finish_time)
        {
            strtf=f[i].arr_time;
        }
        f[i].start_time=strtf;
        f[i].finish_time=strtf+f[i].s_t;
        strtf=f[i].finish_time;
        f[i].wt=f[i].start_time-f[i].arr_time;
        wtf=wtf+f[i].wt;

        s[i].start_time=strts;
        s[i].finish_time=strts+s[i].s_t;
        strts=s[i].finish_time;
        wts=wts+s[i].start_time;
    }


     printf("Grand Chart->   First Come First Serve-:\n");
    printf("%2s","");
    for(i=0;i<n;i++)
    {
        printf("%4c",f[i].process_name);
    }
    puts("");
    for(i=0;i<n;i++)
    {
        printf("%4d",f[i].start_time);
    }
    printf("%4d\n\n",f[n-1].finish_time);



    printf("Grand Chart->   Shortest Job First-:\n");
    printf("%2s","");
    for(i=0;i<n;i++)
    {
        printf("%4c",s[i].process_name);
    }
    puts("");
    for(i=0;i<n;i++)
    {
        printf("%4d",s[i].start_time);
    }
    printf("%4d\n\n",s[n-1].finish_time);
    printf("Grand Chart -> Round Robin-:\n");
    et=0;
    c=0;
    printf("%2s","");
    for(i=0;c<n;i++)
    {
        i=i%n;
        if(bb[i].count!=-1)
        {
            printf("%4c",bb[i].process_name);
        }
        if(bb[i].count==0)
        {
            wtr=wtr+et;
            bb[i].start_time=et;
            bb[i].count++;
            wtr=wtr+et;
        }
        if(bb[i].s_t<=quantum&&bb[i].count!=-1)
        {
            et=et+bb[i].s_t;
            bb[i].s_t=0;
            bb[i].finish_time=et;
            c=c++;
        }
        else if(bb[i].s_t>quantum)
        {
            bb[i].s_t=bb[i].s_t-quantum;
            et=et+quantum;
        }
        if(bb[i].s_t!=0)
        {
            printf("");
        }
        else if(bb[i].s_t==0&&bb[i].count!=-1)
        {
            bb[i].count=-1;
        }
    }
    puts("");
    et=0;
    c=0;
    for(i=0;c<n;i++)
    {
        i=i%n;
        if(ss[i].count!=-1)
        {
            printf("%4d",et);
        }
        if(ss[i].count==0)
        {
            ss[i].start_time=et;
            ss[i].count++;
        }
        if(ss[i].s_t<=quantum&&ss[i].count!=-1)
        {
            et=et+ss[i].s_t;
            ss[i].s_t=0;
            ss[i].finish_time=et;
            c=c++;
        }
        else if(ss[i].s_t>quantum)
        {
            ss[i].s_t=ss[i].s_t-quantum;
            et=et+quantum;
        }
        if(ss[i].s_t==0&&ss[i].count!=-1)
        {
            ss[i].count=-1;
        }
    }
    printf("%4d \n",et);
    puts("Comparison: Average to Wait for Response:");
    printf("FCFS-> %f\n",wtf/n);
    printf("SJF-> %f\n",wts/n);
    printf("RR -> %f\n",wtr/n);
    if(wtf<wts&&wtf<wtr)
    {
        puts("FCFS is more Efficient");
    }
    else if(wts<wtr)
    {
        puts("SJF is more Efficient");
    }
    else
    {
        puts("Round Robin is more Efficient");
    }
    return 0;
}
void sjf(struct process *a,int x)
{
    int i,j;
    struct process temp;
    for(i=x-1;i>=0;i--)
    {
        for(j=0;j<=i-1;j++)
        {
            if(a[j].s_t>a[j+1].s_t)
               {
                   temp=a[j+1];
                   a[j+1]=a[j];
                   a[j]=temp;
               }
        }
    }
}
void fcfs(struct process *a,int x)
{
    int i,j;
    struct process temp;
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

