#include<bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int startTime;
    int finishTime;
    int waitingTime;
    int turnaroundTime;
};

bool compareArrivalTime(const Process &a, const Process &b) {
    return a.arrivalTime < b.arrivalTime;
}

int main(void) {
    int numProcesses;
    cin >> numProcesses;

    Process processes[numProcesses];

    for (int i = 0; i < numProcesses; i++) {
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].id = i + 1;
    }

    sort(processes, processes + numProcesses, compareArrivalTime);

    int currentTime = 0;

    for (int i = 0; i < numProcesses; i++) {
        processes[i].startTime = max(currentTime, processes[i].arrivalTime);
        processes[i].finishTime = processes[i].startTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].finishTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].startTime - processes[i].arrivalTime;

        currentTime = processes[i].finishTime;
    }

    cout << "Process\tArrival Time\tBurst Time\tStart Time\tFinish Time\tTurnaround Time\tWaiting Time" << endl;

    double avgWaitingTime = 0.0, avgTurnaroundTime = 0.0;

    for (int i = 0; i < numProcesses; i++) {
        cout << processes[i].id << "\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t"
             << processes[i].startTime << "\t\t" << processes[i].finishTime << "\t\t"
             << processes[i].turnaroundTime << "\t\t" << processes[i].waitingTime << endl;

        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }

    avgWaitingTime /= numProcesses;
    avgTurnaroundTime /= numProcesses;

    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
}
