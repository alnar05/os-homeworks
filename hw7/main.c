#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct{
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
} Process;

void sortByArrival(Process* arr, int n){
    for (int i = 0; i < n - 1; i++){
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++){
            if (arr[j].arrival_time > arr[j+1].arrival_time){
                // Swap
                Process temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                swapped = true;
            }
        }

        if (!swapped){
            break;
        }
    }
}

void sortByBursttime(Process* arr, int n){
    for (int i = 0; i < n - 1; i++){
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++){
            if (arr[j].burst_time > arr[j+1].burst_time){
                Process temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            } else if (arr[j].burst_time == arr[j+1].burst_time
                && arr[j].arrival_time > arr[j+1].arrival_time){
                Process temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        if (!swapped){
            break;
        }
    }
}


void GanttChart(Process* arr, int n){
    printf("Gantt Chart: ");

    for (int i = 0; i < n; i++) {
        printf("|");
    

        int pad = arr[i].burst_time / 3;
        if (pad < 1) pad = 1;

        for (int k = 0; k < pad; k++) printf(" ");
        printf("P%d", arr[i].pid);
        for (int k = 0; k < pad; k++) printf(" ");
    }
    printf("|\n");
    
    printf("PID     AT     BT     WT     TAT    RT\n");
    for (int i = 0; i < n; i++){
        printf("%-8d%-7d%-7d%-7d%-7d%-d\n", 
            arr[i].pid, 
            arr[i].arrival_time, 
            arr[i].burst_time, 
            arr[i].waiting_time, 
            arr[i].turnaround_time, 
            arr[i].response_time);
    }
}

float average_WT(Process* arr, int n){
    int sumOfWT = 0;
    for (int i = 0; i < n; i++){
        sumOfWT += arr[i].waiting_time;
    }
    return (float)sumOfWT / n;
}

float average_TT(Process* arr, int n){
    int sumOfTT = 0;
    for (int i = 0; i < n; i++){
        sumOfTT += arr[i].turnaround_time;
    }
    return (float)sumOfTT / n;
}

float average_RT(Process* arr, int n){
    int sumOfRT = 0;
    for (int i = 0; i < n; i++){
        sumOfRT += arr[i].response_time;
    }
    return (float)sumOfRT / n;
}




void FCFS(Process* arr, int n){
    sortByArrival(arr, n);

    int current_time = 0;

    for (int i = 0; i < n; i++){
        if (current_time < arr[i].arrival_time){
            current_time = arr[i].arrival_time;
        }
        arr[i].waiting_time = current_time - arr[i].arrival_time;
        arr[i].turnaround_time = arr[i].waiting_time + arr[i].burst_time;
        arr[i].response_time = arr[i].waiting_time;

        current_time += arr[i].burst_time;
    }

    printf("\n=== First Come First Served (FCFS) ===\n");
    GanttChart(arr, n);

    printf("\nAverage Waiting Time: %.2f\n", average_WT(arr, n));
    printf("Average Turnaround Time: %.2f\n", average_TT(arr, n));
    printf("Average Response Time: %.2f\n", average_RT(arr, n));
}

void SJF(Process* arr, int n){
    sortByBursttime(arr, n);

    int current_time = 0;
    int completed = 0;

    int* isCompleted = (int *)calloc(n, sizeof(int));
    Process* execOrder = (Process *)malloc(n * sizeof(Process));
    if (isCompleted == NULL || execOrder == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    while (completed < n){
        int bestIndex = -1;
        int minBurst = INT_MAX;

        for (int j = 0; j < n; j++){
            if (arr[j].arrival_time <= current_time && !isCompleted[j]){
                if (arr[j].burst_time < minBurst) {
                    minBurst = arr[j].burst_time;
                    bestIndex = j;
                }

                else if (arr[j].burst_time == minBurst) {
                    if (arr[j].arrival_time < arr[bestIndex].arrival_time) {
                        bestIndex = j;
                    }
                }
            }
        }

        if (bestIndex != -1){
            arr[bestIndex].waiting_time = current_time - arr[bestIndex].arrival_time;
            arr[bestIndex].response_time = arr[bestIndex].waiting_time;
            arr[bestIndex].turnaround_time = arr[bestIndex].waiting_time + arr[bestIndex].burst_time;
            
            current_time += arr[bestIndex].burst_time;
            isCompleted[bestIndex] = 1;

            execOrder[completed] = arr[bestIndex];
            completed++;

        } else {
            current_time++;
        }
    }

    printf("\n=== Shortest Job First (SJF) ===\n");
    GanttChart(execOrder, n);

    printf("\nAverage Waiting Time: %.2f\n", average_WT(execOrder, n));
    printf("Average Turnaround Time: %.2f\n", average_TT(execOrder, n));
    printf("Average Response Time: %.2f\n", average_RT(execOrder, n));

    free(isCompleted);
    isCompleted = NULL;
    free(execOrder);
    execOrder = NULL;
}


int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process* processes1 = (Process *)malloc(n * sizeof(Process));
    Process* processes2 = (Process *)malloc(n * sizeof(Process));
    if (processes1 == NULL || processes2 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++){
        printf("Enter the arrival time and burst time for process %d: ", i+1);
        Process p;
        p.pid = i + 1;
        scanf("%d %d", &p.arrival_time, &p.burst_time);

        processes1[i] = p;
        processes2[i] = p;
    }

    FCFS(processes1, n);
    SJF(processes2, n);

    free(processes1);
    processes1 = NULL;
    free(processes2);
    processes2 = NULL;
}