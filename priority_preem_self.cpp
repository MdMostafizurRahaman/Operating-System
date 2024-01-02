#include<bits/stdc++.h>
using namespace std;

struct Process {
    int priority;
    int arrivalTime;
    int burstTime;
    int startTime;
    int finishTime;
    int waitingTime;
    int turnaroundTime;
};

int findMinPriority(const Process processes[], const int arrival[], int num, int currentTime) {
    int minIndex = -1;
    int minPriority = INT_MAX;

    for (int i = 0; i < num; i++) {
        if (arrival[i] <= currentTime && processes[i].priority < minPriority && processes[i].burstTime > 0) {
            minPriority = processes[i].priority;
            minIndex = i;
        }
    }

    return minIndex;
}

int main(void) {
    int numProcesses;
    cin >> numProcesses;

    Process processes[numProcesses];

    for (int i = 0; i < numProcesses; i++) {
        cin >> processes[i].priority >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].startTime = 0; // Initialize, will be updated later
    }

    int arrivalTimeCopy[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        arrivalTimeCopy[i] = processes[i].arrivalTime;
    }

    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < numProcesses) {
        int minPriorityIndex = findMinPriority(processes, arrivalTimeCopy, numProcesses, currentTime);

        if (minPriorityIndex == -1) {
            currentTime++;
        } else {
            int shortestBurst = min(processes[minPriorityIndex].burstTime, arrivalTimeCopy[minPriorityIndex + 1] - currentTime);
            processes[minPriorityIndex].burstTime -= shortestBurst;
            processes[minPriorityIndex].startTime = currentTime;
            processes[minPriorityIndex].finishTime = currentTime + shortestBurst;
            arrivalTimeCopy[minPriorityIndex] = currentTime + shortestBurst;
            currentTime += shortestBurst;

            if (processes[minPriorityIndex].burstTime == 0) {
                completedProcesses++;
            }
        }
    }

    // Rest of the code to calculate turnaround time, waiting time, and display the results

    return 0;
}
