#include<bits/stdc++.h>
using namespace std;

struct process {
    string pid;
    int pr,bt,tat,wt;
};

bool compareProcess(process x,process y){
    return x.pr<y.pr;
}

int main(){

    freopen("priority.txt","r",stdin);
    int no_process;
    cin >>no_process;
    vector<process>p(no_process);

    for(int i=0;i<no_process;i++){
        cin >>p[i].pr>>p[i].bt;
        int j = i+1;
        string n = to_string(j);
        p[i].pid = "p"+n;
    }
    sort(p.begin(),p.end(),compareProcess);


    int completion_time=0;
    double total_turnaround_time=0, total_waiting_time=0;
    for(int i=0;i<no_process;i++){
        completion_time += p[i].bt;
        p[i].tat = completion_time;
        p[i].wt = p[i].tat - p[i].bt;
        total_turnaround_time += p[i].tat;
        total_waiting_time += p[i].wt;
    }

    cout<<"\n\n"
        <<"Average turnaround time : "<<total_turnaround_time / no_process<<"\n"
        <<"Average waiting time : "<<total_waiting_time / no_process<<"\n";

    string gantt_chart="|",border ="-";

    for(auto i :p){
        gantt_chart += "  " + i.pid+ "  |";
        border +="-------";
    }
    cout <<border<<endl;
    cout <<gantt_chart<<endl;
    cout <<border<<endl;

    cout <<"0";
    int index=0;
    for(int i=1;i < gantt_chart.length();i++){
        if(gantt_chart[i] == '|'){
            cout << p[index].tat;
            if(p[index++].tat >= 10){
                i++;
            }
        }
        else cout<<" ";
    }

    return 0;
}
