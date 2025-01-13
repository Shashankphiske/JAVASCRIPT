#include <stdio.h>
#include <limits.h>

# define MAX_PROCESSES = 100

// process struct
typedef struct{
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int remaining;
    int wt;
}Process;

// prototyping functions
void fcfs(Process proc[], int n);
void sjf(Process proc[], int n);
void rr(Process proc[], int n, int quantum);
void printaveragetime(Process proc[], int n, const char *algorithm);
void resetprocess(Process proc[], int n);

// reset function
void resetprocess(Process proc[], int n){
    for(int i = 0; i<n; i++){
        proc[i].wt = 0;
        proc[i].tat = 0;
        proc[i].ct = 0;
        proc[i].remaining = proc[i].bt;
    }
}

void fcfc(Process proc[], int n){
    int i;
    int ct = 0;

    for(i = 0; i<n; i++){
        if(ct < proc[i].at){
            ct = proc[i].at;
        }
        proc[i].wt = ct - proc[i].at;
        ct += proc[i].bt;
        proc[i].tat = proc[i].wt + proc[i].bt;
        proc[i].ct = ct;
    }
    printaveragetime(proc, n , "FCFS");
}