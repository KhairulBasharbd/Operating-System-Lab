
#include<bits/stdc++.h>
using namespace std;

void printframes(vector<int> f){
    for(auto i:f){
        if(i == -1)cout <<"-";
        else cout <<i<<" ";
    }
    cout <<endl;
}


int main(){

    int size;
    cin >>size;
    vector<int>frames(size,-1);

    int page,miss=0,index =0;
    while(cin>>page){
        bool found=false;
        for(auto i:frames){
            if(i==page){
               found = true;
               break;
            }
        }

        if(found){
            cout << page << " ->\n";
            continue;
        }
        miss++;
        frames[index]=page;
        index = (index+1) %size;
        cout << page << " -> ";
        printframes(frames);

    }
    cout<< "total page fault : "<<miss;

    return 0;
}


/*
3
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

..............Output:
7 -> 7 - -
0 -> 7 0 -
1 -> 7 0 1
2 -> 2 0 1
0 ->
3 -> 2 3 1
0 -> 2 3 0
4 -> 4 3 0
2 -> 4 2 0
3 -> 4 2 3
0 -> 0 2 3
3 ->
2 ->
1 -> 0 1 3
2 -> 0 1 2
0 ->
1 ->
7 -> 7 1 2
0 -> 7 0 2
1 -> 7 0 1
Total page fault = 15

/*/



