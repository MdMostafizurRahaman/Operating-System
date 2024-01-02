#include<bits/stdc++.h>
using namespace std;

int main()
{
    int no_of_process,quantum;
    cout<<"Enter the number of process and quantum: ";
    cin>>no_of_process>>quantum;
    cout<<"Enter the number of process, arrival time and burst time: \n";

    queue<pair<string, pair<int,int>>>q;
    vector<string>process;
    vector<int>burst_time,arrival_time;
    int max_t=0;

    for(int i=0;i<no_of_process;i++)
    {
        string p_s;
        int a_t, b_t;
        cin>>p_s;
        cin>>a_t;
        cin>>b_t;
        process.push_back(p_s);
        arrival_time.push_back(a_t);
        burst_time.push_back(b_t);
        if(a_t>max_t) max_t=a_t;
    }


    int current_time=0, k=1;
    for(int i=0; i<=max_t;i++){

       for(int j=0;j<no_of_process;j++){
         if(arrival_time[j]==i) q.push(make_pair(process[j],make_pair(arrival_time[j],burst_time[j])));
       }

      if(!q.empty()&&i!=0)
      {
        pair<string,pair<int,int>>p=q.front();
        pair<int,int>p1=p.second;
        int b_t;
        for(int j=0;j<no_of_process;j++){
         if(process[j]==p.first) b_t=burst_time[j];
         }

        cout<<"Current time: "<<current_time-1<< " to " <<current_time<<" running process-> "<<p.first<<" remaining execution time "
        <<q.front().second.second-1<<" of total burst time "<<b_t<<endl;
        q.front().second.second--;

        if(q.front().second.second && k<quantum) {k++;}
        else if(q.front().second.second) {cout<<endl;p=q.front();q.pop();q.push(p);k=1;}
        else {cout<<endl<<"Process----> "<<p.first<< " done at time ----> "<<current_time<<endl<<endl;q.pop();k=1;}
      }
      current_time++;
      if(i==max_t&&!q.empty()) max_t++;
    }
}



