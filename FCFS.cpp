#include<bits/stdc++.h>
using namespace std;

struct process{
    string pid;
    int bt;
    int tat;
    int wt;
};

int main(){

    int burst_time;

    int no_process;
    //cout<<"Enter the no. of process = ";
    cin >> no_process;

    vector<process>p(no_process);
    //cout<<"Enter the burst time = ";
    for(int i=0;i<no_process;i++){
        cin >>burst_time;
        string n = to_string(i);
        p[i].pid = "p" + n;
        p[i].bt = burst_time;
    }

    int completion_time=0;
    vector<int>ct;
    double avg_waiting = 0, avg_turnaround = 0;

    for(auto i:p){
        completion_time += i.bt;
        ct.push_back(completion_time);
        i.tat = completion_time;
        i.wt = i.tat - i.bt;
        avg_waiting += i.wt;
        avg_turnaround += i.tat;
    }

     cout << "\n\n"<< "Average waiting time = " << avg_waiting / no_process << "\n"
         << "Average turnaround time = " << avg_turnaround / no_process << "\n\n";

    string gantt_chart = "|",border = "-";
    for(auto i:p){
        gantt_chart +="  " + i.pid +"  |";
        border +="-------";
    }
    cout <<border<<endl;
    cout <<gantt_chart<<endl;
    cout <<border<<endl;

    cout<<"0";
    int index = 0;
    for (int i = 1; gantt_chart[i]; i++)
    {
        if (gantt_chart[i] == '|')
        {
            cout << ct[index];
            if (ct[index++] >= 10)
            {
                i++;
            }
        }
        else cout << " ";
    }

    return 0;
}

/**
5
13
3
17
4
2

**/
