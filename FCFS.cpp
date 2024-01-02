#include<bits/stdc++.h>
using namespace std;

int main()
{
    int no_of_process;
    cout<<"Enter the number of process: ";
    cin>>no_of_process;

    cout<<"Enter the process and burst time:\n";

    queue<pair<string,int>>q;

    for(int i=0;i<no_of_process;i++)
    {
        string process;
        int burst_time;
        cin>>process;
        cin>>burst_time;
        q.push(make_pair(process,burst_time));
    }

    int current_time=0;
    while(!q.empty())
    {
        pair<string,int>p=q.front();

        q.pop();
        cout<<"Time: "<<current_time<<"----";
        current_time+=p.second;
        cout<<current_time<<" running process -> "<<p.first<<" with burst time "<<p.second<<endl;
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