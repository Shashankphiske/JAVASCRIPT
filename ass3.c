#include <stdio.h>
#include <limits.h>

#define MAX_PROCESSES 100

// Structure to represent a process
typedef struct {
    int id;             // Process ID
    int arrival;        // Arrival time
    int burst;          // Burst time
    int remaining;      // Remaining time (for RR)
    int wait;           // Waiting time
    int turnAround;     // Turnaround time
    int completion;     // Completion time
} Process;

// Function prototypes
void fcfs(Process proc[], int n);
void sjf(Process proc[], int n);
void rr(Process proc[], int n, int quantum);
void printAverageTimes(Process proc[], int n, const char *algorithm);
void resetProcesses(Process proc[], int n);

// Function to reset process attributes
void resetProcesses(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].wait = 0;
        proc[i].turnAround = 0;
        proc[i].completion = 0;
        proc[i].remaining = proc[i].burst; // Reset remaining time for RR
    }
}

void fcfs(Process proc[], int n) {
    int i;
    int currentTime = 0;
    
    for (i = 0; i < n; i++) {
        if (currentTime < proc[i].arrival) {
            currentTime = proc[i].arrival; // Wait until process arrives
        }
        proc[i].wait = currentTime - proc[i].arrival;
        currentTime += proc[i].burst;
        proc[i].turnAround = proc[i].wait + proc[i].burst;
        proc[i].completion = currentTime; // Set completion time
    }

    printAverageTimes(proc, n, "FCFS");
}

void sjf(Process proc[], int n) {
    int i, currentTime = 0, minIndex;
    int completed = 0;
    int isCompleted[n];
    
    for (i = 0; i < n; i++) {
        isCompleted[i] = 0;
    }
    
    while (completed < n) {
        // Find the process with the smallest burst time among the processes that have arrived
        int minBurst = INT_MAX;
        minIndex = -1;
        
        for (i = 0; i < n; i++) {
            if (proc[i].arrival <= currentTime && !isCompleted[i] && proc[i].burst < minBurst) {
                minBurst = proc[i].burst;
                minIndex = i;
            }
        }
        
        if (minIndex != -1) {
            proc[minIndex].wait = currentTime - proc[minIndex].arrival;
            currentTime += proc[minIndex].burst;
            proc[minIndex].turnAround = proc[minIndex].wait + proc[minIndex].burst;
            proc[minIndex].completion = currentTime; // Set completion time
            isCompleted[minIndex] = 1;
            completed++;
        } else {
            currentTime++; // Advance time if no process is ready
        }
    }

    printAverageTimes(proc, n, "SJF");
}

void rr(Process proc[], int n, int quantum) {
    int time = 0;
    int i, done = 0;

    // Round Robin scheduling
    while (done < n) {
        for (i = 0; i < n; i++) {
            if (proc[i].remaining > 0) {
                if (proc[i].arrival > time) {
                    time = proc[i].arrival; // Wait until process arrives
                }
                if (proc[i].remaining > quantum) {
                    time += quantum;
                    proc[i].remaining -= quantum;
                } else {
                    time += proc[i].remaining;
                    proc[i].wait = time - proc[i].burst - proc[i].arrival;
                    proc[i].turnAround = time - proc[i].arrival;
                    proc[i].completion = time; // Set completion time
                    proc[i].remaining = 0;
                    done++;
                }
            }
        }
    }

    printAverageTimes(proc, n, "RR");
}

void printAverageTimes(Process proc[], int n, const char *algorithm) {
    int i;
    float totalWait = 0, totalTurnAround = 0;

    printf("\n%s Scheduling Results:\n", algorithm);
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");

    for (i = 0; i < n; i++) {
        totalWait += proc[i].wait;
        totalTurnAround += proc[i].turnAround;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].id, proc[i].arrival, proc[i].burst, proc[i].wait, proc[i].turnAround, proc[i].completion);
    }

    printf("\nAverage Waiting Time: %.2f", totalWait / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnAround / n);
}

int main() {
    Process proc[MAX_PROCESSES];
    Process procCopy[MAX_PROCESSES];
    int n, i, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        proc[i].id = i + 1;
        scanf("%d %d", &proc[i].arrival, &proc[i].burst);
    }

    // FCFS
    resetProcesses(proc, n);
    printf("\nExecuting FCFS...\n");
    fcfs(proc, n);

    // Make a copy of processes for SJF and RR
    for (i = 0; i < n; i++) {
        procCopy[i] = proc[i];
    }

    // SJF
    resetProcesses(procCopy, n);
    printf("\nExecuting SJF...\n");
    sjf(procCopy, n);

    // Make a copy of processes for RR
    for (i = 0; i < n; i++) {
        procCopy[i] = proc[i];
    }

    // RR
    printf("\nEnter time quantum for RR: ");
    scanf("%d", &quantum);
    resetProcesses(procCopy, n);
    printf("\nExecuting RR...\n");
    rr(procCopy, n, quantum);

    return 0;
}