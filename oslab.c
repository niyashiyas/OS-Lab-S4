#include <stdio.h>
typedef struct{
    int pid;
    int atime;
    int btime;
    int ctime;
    int rtime;
    int wtime;
    int tatime;
}process;

int ganttProcess[] = {};
int ganttTime[] = {};
int tt ;

int findShortest(process p[], int n, int t){
    int shortIndex = -1;
    int shortBtime = 999;
    for(int i=0; i<n; i++){
        if(p[i].atime<=t && p[i].rtime >0 && p[i].rtime<shortBtime){
                printf("P%d rt-%d st-%d\n",p[i].pid, p[i].rtime, shortBtime);
            
                shortIndex = i;
                shortBtime = p[i].rtime;
            
        }
    }
    return shortIndex;
}

void srtf(process p[], int n){
    int t = 0;
    int completed = 0;
    //to find shortest job at any point of time
    while(completed<n){
        int shortest = findShortest(p, n, t);
        if(shortest == -1){
            t++;
            continue;
        }
         
        process *job = &p[shortest];
        job->rtime= (job->rtime-1);
        ganttProcess[t]=job->pid;
        // ganttProcess[t]=t++;
        t++;
        if(job->rtime==0){
            job->ctime= t;
            job->tatime = job->ctime-job->atime;
            job->wtime=job->tatime-job->btime;
            completed++;
        }
    }
    tt = t;
}

void main(){
 int n;
 process p[10];
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 for(int i=0;i<n;i++){
    p[i].pid=(i+1);
    printf("Enter value of arrive time and burst time of process %d: ", (i+1));
    scanf("%d %d", &p[i].atime, &p[i].btime);
    p[i].rtime=p[i].btime;
 }
 srtf(p,n);
 float avg_wt = 0, avg_tat = 0;
 printf("PID\tBurst\tArrival\tCompletion\tTurnaround\tWait\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].btime, p[i].atime, p[i].ctime, p[i].tatime, p[i].wtime);
        avg_wt += p[i].wtime;
        avg_tat += p[i].tatime;
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    printf("\n\tGantt Chart");
    printf("\n--------------------------------------------------------------------------------------------------\n");
    for(int i=0; i<tt; i++){
        printf("|\tP%d\t", ganttProcess[i]);
    }
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("0\t");
    for(int i=1; i<=tt; i++){
        printf("\t%d\t", i);
    }
}
