#include<bits/stdc++.h>
using namespace std;

struct process{
    string pid;
    int bt,tat,wt;
};

bool compareProcess(process x,process y){
    return x.bt<y.bt;
}

int main(){
    freopen("sjf.txt", "r", stdin);
    int no_process;
    cin >> no_process;
    vector<process>p(no_process);

    int burst_time;
    for(int i=0;i<no_process;i++){
        cin>>burst_time;
        int j=i+1;
        string a = to_string(j);
        p[i].pid = "p" + a;
        p[i].bt = burst_time;
    }

    sort(p.begin(),p.end(),compareProcess);

    int completion_time=0;
    double total_turnaround_time=0,total_waiting_time=0;


    for(int i=0; i<no_process; i++){
        completion_time += p[i].bt;
        p[i].tat = completion_time;
        p[i].wt = p[i].tat - p[i].bt;
        total_turnaround_time += p[i].tat;
        total_waiting_time += p[i].wt;
    }
    cout << "\n\n"
         << "Average waiting time = " << total_waiting_time / no_process << "\n"
         << "Average turnaround time = " << (total_turnaround_time/ no_process) << "\n\n";

    string gantt_chart="|",border="-";
    for(auto i:p){
        gantt_chart += "  " + i.pid+ "  |";
        border += "-------";
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
            cout << p[index].tat;
            if (p[index++].tat >= 10)
            {
                i++;
            }
        }
        else cout << " ";
    }
    return 0;
}


/*
4
6
8
7
3


*/
