#include<bits/stdc++.h>
using namespace std;

int main()
{
    struct comparator{
       bool operator()(pair<string,pair<int,pair<int,int>>>&a, pair<string,pair<int,pair<int,int>>>&b)
       {
           if(a.second.second.second == b.second.second.second) return a.second.second.first>b.second.second.first;
           return a.second.second.second>b.second.second.second;
       }
    };

    priority_queue<pair<string, pair<int,pair<int,int>>>, vector<pair<string,pair<int,pair<int,int>>>>, comparator>pq;

    int no_of_process;
    cout<<"Enter the number of process: ";
    cin>>no_of_process;
    cout<<"Enter the number of process, arrival time, burst time and priority: \n";

    vector<string>process;
    vector<int>burst_time,arrival_time,priority;
    int max_t=0;

    for(int i=0;i<no_of_process;i++)
    {
        string p_s;
        int a_t, b_t,p_r;
        cin>>p_s;
        cin>>a_t;
        cin>>b_t;
        cin>>p_r;
        process.push_back(p_s);
        arrival_time.push_back(a_t);
        burst_time.push_back(b_t);
        priority.push_back(p_r);
        if(a_t>max_t) max_t=a_t;
    }


    int current_time=1;
    for(int i=0; i<=max_t;i++){
       for(int j=0;j<no_of_process;j++){
         if(arrival_time[j]==i) pq.push(make_pair(process[j],make_pair(arrival_time[j],make_pair(burst_time[j],priority[j]))));
       }
    if(!pq.empty())
    {
        pair<string,pair<int,pair<int,int>>>p=pq.top();
        pq.pop();
        pair<int,pair<int,int>>p1=p.second;
        int b_t,p_r;
        for(int j=0;j<no_of_process;j++){
         if(process[j]==p.first) {b_t=burst_time[j];p_r=priority[j];}
         }
        cout<<"Current time: "<<current_time-1<< " to " <<current_time<<" running process-> "<<p.first<<" remaining execution time "
         <<p.second.second.first-1<<" of total burst time "<<b_t<<endl;

        p.second.second.first--;
        if(p.second.second.first) pq.push(p);
        else cout<<endl<<"Process----> "<<p.first<< " done at time ----> "<<current_time<<" priority ----> "<<p_r<<endl<<endl;
    }
     current_time++;
     if(i==max_t&&!pq.empty()) max_t++;
    }
}



