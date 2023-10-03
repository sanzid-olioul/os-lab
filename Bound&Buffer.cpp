#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<string>buffer;
    int index=0,n,option;
    string var;
    cout<<"Choose option"<<endl<<"1.Produce"<<endl<<"2.Consume"<<endl<<"3.exit"<<endl<<endl;
    while(true){
            cout<<"Enter your choice:"<<endl;
    cin>>option;
    if(option == 1){
            cout<<"Enter shared variable:"<<endl;
            cin>>var;
            buffer.push(var);
            index++;
            cout<<"Producer insert variable "<<var<<" into buffer"<<endl;
    }
    else if(option == 2){
        if(index>0){
            var = buffer.front();
            buffer.pop();
            cout<<"Consumer get "<<var<<" from buffer"<<endl;
            index--;
        }
        else{
            cout<<"Buffer is empty!!!"<<endl;
        }
    }else if(option == 3){
         break;
    }
    else{
        cout<<"Enter valid option!!!"<<endl;
    }
    }

    return 0;


}
/*
#include<stdio.h>
int mutex=1,full=0,empty=3,x=0;
main()
{
int n;
void producer();
void consumer();
int wait(int);
int signal(int);
printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
while(1) {
printf("\nENTER YOUR CHOICE\n");
scanf("%d",&n);
switch(n)
{ case 1:
if((mutex==1)&&(empty!=0))
producer();
else
printf("BUFFER IS FULL");
break;
case 2:
if((mutex==1)&&(full!=0))
consumer();
else
printf("BUFFER IS EMPTY");
break;
case 3:
break;
}
}
}
int wait(int s) {
return(--s); }
int signal(int s) {
return(++s); }
void producer() {
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
x++;
printf("\nproducer produces the item%d",x);
mutex=signal(mutex); }
void consumer() {
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
printf("\n consumer consumes item%d",x);
x--;
mutex=signal(mutex); }
*/
