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

int findHighestPriority(const Process processes[], const int arrival[], int num, int currentTime) {
    int highestPriorityIndex = -1;
    int highestPriority = INT_MAX;

    for (int i = 0; i < num; i++) {
        if (arrival[i] <= currentTime && processes[i].priority < highestPriority) {
            highestPriority = processes[i].priority;
            highestPriorityIndex = i;
        }
    }

    return highestPriorityIndex;
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
        int highestPriorityIndex = findHighestPriority(processes, arrivalTimeCopy, numProcesses, currentTime);

        if (highestPriorityIndex == -1) {
            currentTime++;
        } else {
            int index = highestPriorityIndex;

            processes[index].startTime = currentTime;
            processes[index].finishTime = currentTime + processes[index].burstTime;
            arrivalTimeCopy[index] = processes[index].finishTime;
            completedProcesses++;
            currentTime = processes[index].finishTime;
        }
    }

    // Calculate turnaround time, waiting time, and display the results

    return 0;
}
