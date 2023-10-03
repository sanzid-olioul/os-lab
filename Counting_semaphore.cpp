#include<bits/stdc++.h>
using namespace std;
int cs=0;
int s;
int n;
queue<string>pcb;
queue<string>critical_section;

int wait(int s)
{
 string process;
 s = s -1;

 if(s<0)
 {
     cout<<"Critical Section is full with processes!!!!!!!"<<endl;
     cout<<"Enter process to entry suspend section "<<endl;
     cin>>process;
     ///sleep()
    pcb.push(process);
 }
 else{

 cout<<"Enter process to entry critical section "<<endl;
 cin>>process;
        critical_section.push(process);

 }
 return s;
}

int signal(int s)
{
 s = s +1;
 if(s <= 0)
 {
     if(!pcb.empty() && !critical_section.empty())
     {
     string temp = pcb.front();
     pcb.pop();
     critical_section.push(temp);
     cout<<"Entering "<<temp<<" to Critical section"<<endl;
     string temp2= critical_section.front();
     critical_section.pop();
     cout<<temp2<<" Exit from critical section"<<endl;
     }else{
     cout<<"Critical Section is empty!!!!"<<endl;
     }

 }
 else{
    string t = critical_section.front();
    critical_section.pop();
    cout<<t<<" Exit from critical section"<<endl;
 }
 return s;
}

int main()
{

    int n,option;
    cout<<"Enter Semaphore value "<<endl;
    cin>>n;

s= n;
 cout<<"Choose option"<<endl<<"1.wait() function call to entry critical section"<<endl<<"2.signal() function to exit from critical section"<<endl<<"3. exit"<<endl;
cout<<endl<<endl;

    while(true){
            cout<<"Option: ";
          cin>>option;
    if(option== 1){
         s = wait(s);
    }
    else if(option == 2)
    {
        s  = signal(s);
    }
    else if(option == 3)
    {
        break;
    }
    else{
        cout<<"Enter valid option !!!"<<endl;
    }

    cout<<endl;
    }

    return 0;


}
