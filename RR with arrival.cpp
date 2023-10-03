#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter the number of process: "<<endl;
    int n,at,bt,ct=0,q; cin>>n; vector<pair<int, int>>v; int btt[n];
    queue<int>ready;
    map<int,int>gantt;

    cout<<"Enter the process's arrival time and burst time : "<<endl;
    for(int i=0; i<n;i++){
    cin>>at>>bt; btt[i]=bt;

    v.push_back(make_pair(at,bt));
    }

    sort(v.begin(),v.end());
    cout<<"Enter the quantum: "<<endl;
    cin>>q;

    int j=0,ff=1;
    gantt[0]=0;
    ready.push(j); int sumr=0,k=0;
    int temp=0; int it=0,s;
    while (!ready.empty()){
            temp=v[it].second-q;

    if(v[it].second!=0){

        if(temp>=0){
        v[it].second=temp;
        sumr+=q;
        gantt[j+1]=sumr; //gantt[j]+q;
        }
        else{
        sumr+=v[it].second;
        gantt[j+1]=sumr; v[it].second=0; //gantt[j]+v[it].second;
        }
    }else{
        ready.pop();
        j=ready.front(); it=j;
    }


    int snt=j,flag=0;
    if(ff<n){
    for(s=it+1;s<n;s++){
        if(v[s].first<=gantt[j+1]){
        ready.push(s); flag=1; ff++;

        }
    }
    }

    if(temp>0) {ready.push(j);  flag=1;}// jodi at soto hoi current time er theke

    if(flag==1){ready.pop(); j=ready.front(); it=j;}



    }
    cout<<"CT: "<<endl; int z=0;
    for(auto m:gantt){if(z==0){z++; continue;}

    cout<<m.second<<endl;}

    int tat[n],wt[n],awt,summ=0;


    for(int i=1;i<=n;i++){
        tat[i-1]=gantt[i]-v[i-1].first;
        wt[i-1]=tat[i-1]-btt[i-1];

        summ+=wt[i-1];
    }

    cout<<"TAT: "<<endl;
    for(auto a:tat){
    cout<<a<<endl;
    }

    cout<<"WT: "<<endl;
    for(auto a:wt){
    cout<<a<<endl;
    }

    cout<<"The average waiting time is: "<<setprecision(2)<<float(summ*1.0/n*1.0)<<endl;
    return 0;
}

