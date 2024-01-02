#include <bits/stdc++.h>
using namespace std;

struct Process {
    int arrivalTime;
    int burstTime;
    int startTime;
    int finishTime;
};

vector<int> grant_chart;

int num;

int findShortestJob(Process processes[], int currentTime)
{
    int shortestJob = -1;
    int shortestBurst = INT_MAX;

    for (int i = 0; i < num; i++)
    {
        if (processes[i].arrivalTime <= currentTime && processes[i].burstTime < shortestBurst && processes[i].burstTime > 0)
        {
            shortestBurst = processes[i].burstTime;
            shortestJob = i;
        }
    }

    return shortestJob;
}

int main(void)
{
    cin >> num;
    Process processes[num];

    for (int i = 0; i < num; i++)
    {
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
    }

    for (int i = 0; i < num; i++)
    {
        processes[i].startTime = -1;
    }

    int currentTime = 0;

    while (true)
    {
        int shortestJob = findShortestJob(processes, currentTime);

        if (shortestJob == -1)
            break;

        if (processes[shortestJob].startTime == -1)
            processes[shortestJob].startTime = currentTime;

        processes[shortestJob].burstTime--;
        currentTime++;

        if (processes[shortestJob].burstTime == 0)
            processes[shortestJob].finishTime = currentTime;

        grant_chart.push_back(shortestJob);
    }

    cout << "Arrival_time   " << "Burst_time   " << "Starting_time   " << "Complition_time   " << "TurnOut_time   " << "Waiting_time" << endl;

    for (int i = 0; i < num; i++)
        cout << processes[i].arrivalTime << "               " << processes[i].burstTime << "               " << processes[i].startTime << "               " << processes[i].finishTime << "               " << processes[i].finishTime - processes[i].arrivalTime << "               " << processes[i].startTime - processes[i].arrivalTime << endl;

    double avgW = 0.0000, avgT = 0.0000;

    for (int i = 0; i < num; i++)
    {
        avgW = avgW + processes[i].startTime - processes[i].arrivalTime;
        avgT = processes[i].finishTime - processes[i].arrivalTime + avgT;
    }

    cout << "AVG waiting time is  " << avgW / num << endl;
    cout << "AVG turn out time is  " << avgT / num << endl;
}

