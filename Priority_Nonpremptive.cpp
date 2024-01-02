#include<bits/stdc++.h>
using namespace std;

int main()
{
    struct comparator{
       bool operator()(pair<string,pair<int,int>>&a, pair<string,pair<int,int>>&b)
       {
           if(a.second.second == b.second.second) return a.second.first>b.second.first;
           return a.second.second>b.second.second;
       }
    };

    priority_queue<pair<string, pair<int,int>>, vector<pair<string,pair<int,int>>>, comparator>pq;

    int no_of_process;
    cout<<"Enter the number of process: ";
    cin>>no_of_process;
    cout<<"Enter the number of process, burst time and priority: \n";

    for(int i=0;i<no_of_process;i++)
    {
        string process;
        int burst_time, priority;
        cin>>process;
        cin>>burst_time;
        cin>>priority;
        pq.push(make_pair(process,make_pair(burst_time,priority)));
    }

    int current_time=0;
    while(!pq.empty())
    {
        pair<string,pair<int,int>>p=pq.top();
        pq.pop();
        cout<<"Time: "<<current_time<<"----";
        current_time+=p.second.first;
        cout<<current_time<<" running process -> "<<p.first<<" with burst time "<<p.second.first<<" and priority-> "<<p.second.second<<endl;
    }
}

/*
5
P1 10
P2 29
P3 3
P4 7
P5 12
*/


