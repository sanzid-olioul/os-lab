#include<bits/stdc++.h>
using namespace std;

class process{
    public:
int id,at,bt,pr,remain;
};

bool compareID(process a, process b)
{
    if(a.id != b.id)
    {
        return a.id<b.id;
    }
}
bool compareAT(process a, process b)
{
    if(a.at != b.at)
    {
        return a.at<b.at;
    }
}
bool compareBT(process a, process b)
{
    if(a.bt != b.bt)
    {
        return a.bt<b.bt;
    }
}

bool comparePR(process a, process b)
{
    if(a.pr != b.pr)
    {
        return a.pr<b.pr;
    }
}

int main()
{
    int t;
    cout<<"Enter 1 for non preemptive and 2 for preemptive "<<endl;
    cin>>t;
    process p[100];
    int n,j=1,ct[100]={0};
    vector<pair<int , int>>v;
    cout<<"Enter the number of process: "<<endl;
    cin>>n;
    cout<<"Enter id, priority, arrival and burst time for all processes: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].id>>p[i].pr>>p[i].at>>p[i].bt;
        p[i].remain = p[i].bt;
    }
    if(t==1){
    sort(p,p+n,compareAT);
    ct[0] = p[0].at + p[0].bt;
    int c = ct[0];
    int f = p[0].id;
    cout<<ct[0]<<" ";
    v.push_back(make_pair(f,c));
    sort(p,p+n,comparePR);
    for(int i=0;i<n;i++)
    {
       if(p[i].id == f)
            continue;
       ct[j] = ct[j-1]+p[i].bt;
       cout<<ct[j]<<" ";
       v.push_back(make_pair(p[i].id, ct[j]));
       j++;
    }
    sort(p,p+n,compareID);
    sort(v.begin(),v.end());
    int tat[n],wt[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        tat[i] = ct[i] - p[i].at;
        wt[i] = tat[i] - p[i].bt;
        sum += wt[i];
    }
    float avg = float(sum/(float(n)));
    cout<<"Average waiting time "<<setprecision(2)<<avg<<endl;
    }

    else{
        sort(p,p+n,comparePR);
        int current = 0;
        bool completed[n] = {false};
        while(true)
        {
           int highest_priority = -1;
    int select_p = -1;

    for(int i=0;i<n;i++)
    {
        if(p[i].at <= current && completed[i]!=true)
        {
            if(p[i].pr <highest_priority || highest_priority == -1)
            {
                highest_priority = p[i].pr;
                select_p = i;
            }
        }
    }

    if(select_p == -1)
    {
       int min_value = INT_MAX;
       for(int i=0;i<n;i++)
       {
           if(!completed[i] && p[i].at > current)
           {
               min_value = min(min_value,p[i].at);
           }
       }
       if(min_value == INT_MAX)
        break;
       else{
        current = min_value;
        continue;
       }
    }
    p[select_p].remain--;
    if(p[select_p].remain == 0)
    {
        ct[select_p] = current+1;
        completed[select_p] = true;
    }
    current++;
        }
        cout<<" CT"<<endl;

        for(int i=0;i<n;i++)
        {
            cout<<ct[i]<<endl;
        }
    }
}
