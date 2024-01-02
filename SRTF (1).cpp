#include<bits/stdc++.h>
using namespace std;

vector<int>chart;

int num;

int mini(int arrival[])
{
    int minimum=1000;
    int idx;
    int m=1000;

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


    cin>>num;
    int arr_time[num],burst_time[num],t_time[num],w_time[num],st_time[num],fin_time[num],arrival[num],b[num];
    int min_b=1000;


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
      b[i]=burst_time[i];
    }

    int index=mini(arrival);




    for(int i=0;i<num;i++)
    {
        if(arrival[i]==arrival[index]&&b[i]<min_b)
        {

            index=i;
            min_b=b[i];
        }


    }

    chart.push_back(index);

    b[index]=b[index]-1;

    int countn;


    while(1)
    {



       countn=0;


        int sizeG=chart.size();

        int mb=100000000;

       for(int i=0;i<num;i++)
       {
         if(arrival[i]<=sizeG&&b[i]<mb&&b[i]>0)
         {
             index=i;
             mb=b[index];
         }

       }



      chart.push_back(index);

      b[index]=b[index]-1;



       for(int i=0;i<num;i++)
       {
           if(b[i]>0)
           {
               countn=countn+1;

           }

       }



        if(countn==0)break;



    }







  for(int i=0;i<num;i++)
  {
      for(int j=0;j<chart.size();j++)
      {
          if(chart[j]==i)fin_time[i]=j+1;
      }
  }

   // Print the header
cout << setw(14) << left << "Arrival_time";
cout << setw(14) << left << "Burst_time";
cout << setw(20) << left << "Completion_time";
cout << setw(15) << left << "Turnaround_time";
cout << setw(15) << left << "Waiting_time";
cout << endl;

// Print the individual process details
for (int i = 0; i < num; i++) {
    cout << setw(14) << left << arr_time[i];
    cout << setw(14) << left << burst_time[i];
    cout << setw(20) << left << fin_time[i];
    cout << setw(15) << left << fin_time[i] - arr_time[i];
    cout << setw(15) << left << fin_time[i] - arr_time[i] - burst_time[i];
    cout << endl;
}

double avgW = 0.0, avgT = 0.0;

for (int i = 0; i < num; i++) {
    avgW += fin_time[i] - arr_time[i] - burst_time[i];
    avgT += fin_time[i] - arr_time[i];
}

// Print the average waiting and turnaround times
cout << "AVG waiting time is  " << fixed << setprecision(4) << avgW / num << endl;
cout << "AVG turnaround time is  " << fixed << setprecision(4) << avgT / num << endl;

}
/*
5
2 1
1 5
4 1
0 6
2 3
*/
