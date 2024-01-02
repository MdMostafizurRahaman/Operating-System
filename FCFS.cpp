#include<bits/stdc++.h>
using namespace std;

int num;

int mini(int arrival[])
{
    int minimum=1000;
    int idx;

    for(int i=0;i<num;i++)
    {
        if(arrival[i]<minimum)
        {
            minimum=arrival[i];
            idx=i;
        }
    }

    return idx;
}

int main(void)
{

    //int num;
    cin>>num;
    int arr_time[num],burst_time[num],t_time[num],w_time[num],st_time[num],fin_time[num],arrival[num];



    for(int i=0;i<num;i++)
    {
        cin>>arr_time[i]>>burst_time[i];
    }

    for(int i=0;i<num;i++)
    {
      arrival[i]=arr_time[i];
    }

    for(int i=0;i<num;i++)
    {
        int index=mini(arrival);

        arrival[index]=1000;

        if(index==0)
        {
            st_time[index]=arr_time[index];
            fin_time[index]=st_time[index]+burst_time[index];
        }



       else
       {
           if(st_time[index]<=fin_time[index-1])st_time[index]=fin_time[index-1];
           else
            st_time[index]=arr_time[index];


          fin_time[index]=st_time[index]+burst_time[index];

    }

    }

   cout << setw(14) << left << "Arrival_time";
cout << setw(14) << left << "Burst_time";
cout << setw(14) << left << "Starting_time";
cout << setw(18) << left << "Completion_time";
cout << setw(16) << left << "Turnaround_time";
cout << setw(15) << left << "Waiting_time";
cout << endl;

for (int i = 0; i < num; i++) {
    cout << setw(14) << left << arr_time[i];
    cout << setw(14) << left << burst_time[i];
    cout << setw(14) << left << st_time[i];
    cout << setw(18) << left << fin_time[i];
    cout << setw(16) << left << fin_time[i] - arr_time[i];
    cout << setw(15) << left << st_time[i] - arr_time[i];
    cout << endl;
}

double avgW = 0.0, avgT = 0.0;

for (int i = 0; i < num; i++) {
    avgW += st_time[i] - arr_time[i];
    avgT += fin_time[i] - arr_time[i];
}

cout << "AVG waiting time is  " << fixed << setprecision(4) << avgW / num << endl;
cout << "AVG turnaround time is  " << fixed << setprecision(4) << avgT / num << endl;

}


