#include<bits/stdc++.h>
using namespace std;

struct process {
    string pid;
    vector<int> allocation,max_need,current_need;
};

bool is_safe(vector<int> available,vector<process> x){

    string sequence = "";
    int no_process = x.size(),no_resource=available.size();
    vector<bool> finish(no_process,false);

    while(1){
        bool found = false;
        for(int i=0;i<no_process;i++){
            if (finish[i]) continue;
            bool ok =true;
            for(int j=0;j<no_resource;j++){
                if(x[i].current_need[j] > available[j]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                found = true;
                finish[i] = true;
                for(int j=0;j<no_resource;j++){
                    available[j] += x[i].allocation[j];
                }
                sequence += x[i].pid + "  ";
            }
        }
        if(!found) break;
    }

    for(int i=0;i<no_process;i++){
        if(!finish[i]) return false;
    }

    cout <<"\n\n"<< sequence << "\n\n";

    return true;
}

int main(){

    freopen("bankers.txt","r",stdin);
    int no_resource;
    cin >> no_resource;
    vector<int>available(no_resource);
    for(int i=0;i<no_resource;i++){
        cin>>available[i];
    }

    int no_process;
    cin >>no_process;
    vector<process>x(no_process);

    for(int i=0;i<no_process;i++){
        x[i].allocation.resize(no_resource);
        x[i].max_need.resize(no_resource);
        x[i].current_need.resize(no_resource);

        cin>> x[i].pid;
        for(int j=0;j<no_resource;j++){
            cin >> x[i].allocation[j];
        }
        for(int j=0;j<no_resource;j++){
            cin >> x[i].max_need[j];

            x[i].current_need[j] = x[i].max_need[j] - x[i].allocation[j];
        }
    }

    if(is_safe(available,x)){
         cout << "The system is in a safe state\n";
    }
    else cout << "The system is not in a safe state!\n";
    return 0;
}


/*//... Input Output:

...............Input:
3
3 3 2
5
T0   0 1 0   7 5 3
T1   2 0 0   3 2 2
T2   3 0 2   9 0 2
T3   2 1 1   2 2 2
T4   0 0 2   4 3 3

..............Output:

T1 T3 T4 T0 T2
The system is in a safe state

*/
