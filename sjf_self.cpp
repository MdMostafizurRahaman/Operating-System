#include<bits/stdc++.h>
using namespace std;

struct Process {
    int arrivalTime;
    int burstTime;
    int startTime;
    int finishTime;
    int waitingTime;
    int turnaroundTime;
};

int findMinBurst(const Process processes[], const int arrival[], int num, int currentTime) {
    int minIndex = -1;
    int minBurst = INT_MAX;

    for (int i = 0; i < num; i++) {
        if (arrival[i] <= currentTime && processes[i].burstTime < minBurst && processes[i].burstTime > 0) {
            minBurst = processes[i].burstTime;
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
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].startTime = 0; // Initialize, will be updated later
    }

    int arrivalTimeCopy[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        arrivalTimeCopy[i] = processes[i].arrivalTime;
    }

    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < numProcesses) {
        int shortestIndex = findMinBurst(processes, arrivalTimeCopy, numProcesses, currentTime);

        if (shortestIndex == -1) {
            currentTime++;
        } else {
            processes[shortestIndex].startTime = max(currentTime, processes[shortestIndex].arrivalTime);
            processes[shortestIndex].finishTime = processes[shortestIndex].startTime + processes[shortestIndex].burstTime;
            arrivalTimeCopy[shortestIndex] = 1000000000;
            completedProcesses++;
            currentTime = processes[shortestIndex].finishTime;
        }
    }

    cout << "Arrival Time   " << "Burst Time   " << "Starting Time   "
         << "Completion Time   " << "Turnaround Time   " << "Waiting Time" << endl;

    double avgWaitingTime = 0.0, avgTurnaroundTime = 0.0;

    for (int i = 0; i < numProcesses; i++) {
        processes[i].turnaroundTime = processes[i].finishTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        cout << processes[i].arrivalTime << "              " << processes[i].burstTime << "            "
             << processes[i].startTime << "             " << processes[i].finishTime << "              "
             << processes[i].turnaroundTime << "              " << processes[i].waitingTime << endl;

        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }

    avgWaitingTime /= numProcesses;
    avgTurnaroundTime /= numProcesses;

    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
}
