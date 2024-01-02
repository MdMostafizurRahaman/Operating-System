#include<bits/stdc++.h>
using namespace std;

vector<int>grant_chart;

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
    int arr_time[num],burst_time[num],t_time[num],w_time[num],st_time[num],fin_time[num],arrival[num],b[num],priority[num];



    for(int i=0;i<num;i++)
    {
        cin>>priority[i]>>arr_time[i]>>burst_time[i];
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

    int min_b=priority[index];



    for(int i=0;i<num;i++)
    {
        if(arrival[i]==arrival[index]&&priority[i]<min_b)
        {

            index=i;
            min_b=priority[i];
        }


    }

    grant_chart.push_back(index);

    b[index]=b[index]-1;

    int countn;


    while(1)
    {



       countn=0;


        int sizeG=grant_chart.size();

        int mb=100000000;

       for(int i=0;i<num;i++)
       {
         if(arrival[i]<=sizeG&&priority[i]<mb&&b[i]>0)
         {
             index=i;
             mb=priority[index];
         }

       }


      grant_chart.push_back(index);

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
      for(int j=0;j<grant_chart.size();j++)
      {
          if(grant_chart[j]==i)fin_time[i]=j+1;
      }
  }





   cout << "Arrival_time   " << "Burst_time   " << "Complition_time   " << "TurnOut_time   " << "Waiting_time" << endl;

for (int i = 0; i < num; i++) {
    cout << setw(14) << left << arr_time[i];
    cout << setw(14) << left << burst_time[i];
    cout << setw(18) << left << fin_time[i];
    cout << setw(16) << left << fin_time[i] - arr_time[i];
    cout << setw(15) << left << fin_time[i] - arr_time[i] - burst_time[i];
    cout << endl;
}

double avgW = 0.0, avgT = 0.0;

for (int i = 0; i < num; i++) {
    avgW += fin_time[i] - arr_time[i] - burst_time[i];
    avgT += fin_time[i] - arr_time[i];
}

cout << "AVG waiting time is  " << fixed << setprecision(4) << avgW / num << endl;
cout << "AVG turn out time is  " << fixed << setprecision(4) << avgT / num << endl;

}
/*
5
3 0 8
4 1 2
4 3 4
5 4 1
2 5 6
*/

