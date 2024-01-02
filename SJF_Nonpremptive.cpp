#include<bits/stdc++.h>
using namespace std;

int main()
{
    struct comparator{
       bool operator()(pair<string,int>&a, pair<string,int>&b)
       {
           return a.second>b.second;
       }
    };

    priority_queue<pair<string,int>, vector<pair<string,int>>, comparator>pq;

    int no_of_process;
    cout<<"Enter the number of process: ";
    cin>>no_of_process;
    cout<<"Enter the process and its burst time:\n";
    for(int i=0;i<no_of_process;i++)
    {
        string process;
        int burst_time;
        cin>>process;
        cin>>burst_time;
        pq.push(make_pair(process,burst_time));
    }

    int current_time=0;
    while(!pq.empty())
    {
        pair<string,int>p=pq.top();
        pq.pop();
        cout<<"Time: "<<current_time<<"___";
        current_time+=p.second;
        cout<<current_time<<" running process -> "<<p.first<<" with burst time "<<p.second<<endl;
    }
}
