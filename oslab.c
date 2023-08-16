#include <stdio.h>

typedef struct{
    int at,bt,ct,wt,rt,tat,pid;
} process;
int tt;
int ganttProcess[] = {};

int findshortest(process p[], int n, int t){
    int srtIndex=-1;
    int srtbtime=999;
    for(int i=0;i<n;i++){
        if(p[i].at<=t && p[i].rt>0 && p[i].rt<srtbtime){
            srtbtime = p[i].rt;
            srtIndex = i;
        }
    }
    return srtIndex;
}

void srtf(process p[], int n){
    int t=0;
    int completed =0;
    while (completed<n){
        int srt = findshortest(p, n, t);
        if(srt==-1){
            t++;
            continue;
        }
        process *job = &p[srt];
        job->rt--;
        ganttProcess[t] = job->pid;
        t++;
        if(job->rt==0){
            job->ct=t+job->rt;
            job->tat=job->ct-job->at;
            job->wt=job->tat-job->bt;
            completed++;
        }
    }
    tt=t;
}

void main(){
    int n;
    printf("enter no of processes: ");
    scanf("%d", &n);
    process p[n];
    for(int i=0;i<n;i++){
        printf("enter atime and btme of process %d: ", i+1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid=i+1;
        p[i].rt=p[i].bt;
    }
    srtf(p, n);
    printf("Process\tatime\tbtime\tctime\ttatime\twtime");
    for(int i=0; i<n; i++){
        printf("\nP%d\t%d\t%d\t%d\t%d", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nGantt Chart\n-------------------------------------------------------------------------------------------------------------------\n");
    for(int i=0; i<tt; i++){
        printf("| P%d ", ganttProcess[i]);
    }
    printf("\n---------------------------------------------------------------------------------------------------------------\n");
    for(int i=0; i<tt;i++){
        printf("%d    ", i);
    }
}