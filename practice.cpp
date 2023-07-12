#include<bits/stdc++.h>
using namespace std;



int main(){
    //freopen("priority.txt","r",stdin);

    string operation;
    cin >>operation;
    cin.ignore();
    if(operation =="create"){
        string name;
        getline(cin,name);
        ofstream newfile(name.c_str());
        newfile <<"Hi";
        newfile.close();
    }
    else if(operation =="delete"){
        string name;
        getline(cin,name);
        int mark = remove(name.c_str());

    }

    else if(operation =="copy"){
        string name;
         string name1;
        getline(cin,name);
                getline(cin,name1);
        int mark = remove(name.c_str());

    }


    return 0;
}

//C:\Users\Khairul_Bashar\Desktop\a.txt
