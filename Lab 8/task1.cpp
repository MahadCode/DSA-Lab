#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Customer{
    int customerID;
    int arrivalTime;
    int serviceTime;
};


int  simulateBankQueue(Customer customers[], int size, int c){
    
    queue<Customer> c1;
    queue<Customer> c2;
    queue<Customer> c3;
    for(int i=0; i<size; i++){
        Customer curr=customers[i];
        if(curr.customerID==1){
            c1.push(curr);
        }
        else if(curr.customerID==2){
            c2.push(curr);
        }
        else if(curr.customerID==3){
            c3.push(curr);
        }
    }
    
    
    int count=0;
    bool newCounter=false;

    if(c==1 || c==2){
       queue<Customer> counter1;
       queue<Customer> counter2;
       int waitingTime[2]={0};
       int counter[2]={0};
       int currentTime=0;
       while(!c1.empty()){
        Customer curr=c1.front();
        if(curr.arrivalTime==currentTime){
            if(counter1.size()==10){
                newCounter=true;
              if(c==1){
                count=10;
              }
              else{
                count=counter2.size()+c1.size();
                if(count>10){
                    count=10;
                }
              }
              break;
            }

            if(counter2.size()==10){
                newCounter=true;
                if(c==2){
                  count=10;
                }
                else{
                  count=counter1.size()+c1.size();
                  if(count>10){
                      count=10;
                  }
                }
                break;
              }

            

            if(waitingTime[0]==0 && waitingTime[1]==0){
                counter2.push(curr);
                waitingTime[1]+=curr.serviceTime;
                counter[1]++;
            }
            else if(waitingTime[1]<=waitingTime[0]){
                counter2.push(curr);
                waitingTime[1]+=curr.serviceTime;
                counter[1]++;
            }
            else{
                counter1.push(curr);
                waitingTime[0]+=curr.serviceTime;
                counter[0]++;
            }


            
            c1.pop();
        }
        

        if(waitingTime[0]>0){
            waitingTime[0]--;
        }
        
        if(waitingTime[1]>0){
            waitingTime[0]--;
        }
        

        currentTime++;

        
       }

    }
    else if(c==2){
        queue<Customer> counter;
        int currentTime=0;
        while(!c1.empty()){
         Customer curr=c2.front();
         if(curr.arrivalTime==currentTime){
            counter.push(curr);    
         }

        }

        
    }
    else{

    }

}



int main(){

}