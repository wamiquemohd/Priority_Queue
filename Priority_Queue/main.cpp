/*Code for Implementing Ready Queue
  Note: if task have same priority, then their order in the queue is considered.

  Author: Mohd. Wamique
  Date 13/10/20
*/

#include "Task.h"

/*This Function is used to print the contents of Priority queue*/
void Print_Pq(std::priority_queue <Task ,std::vector<Task>,CompareClass> copy_Pq){
    std::cout<< "Members in Priority Queue: ";
    Task T1;

    /*copy_Pq.empty(): Checks if the queue is empty and returns its status.*/
    if(copy_Pq.empty()){
        std::cout<< "It's Empty Now"<<std::endl;
    }else{
        while(!copy_Pq.empty()){

            /* copy_Pq.top(): Returns a reference to the topmost element of the priority queue.*/
             T1 = copy_Pq.top();
            std::cout << T1.Priority<<"\t";

            /*copy_Pq.pop(): Removes the first element from the priority queue.*/
            copy_Pq.pop();
        }
        std::cout<<"\n"<<std::endl;
    }
 }

 /*Function for Removing data from ready Queue*/
 void Extract_Data_From_ReadyQueue(std::priority_queue <Task ,std::vector<Task>,CompareClass> &Pq){

    std::cout<< "Fetching data from Ready Queue:\n"<<std::endl;
    Task T1;
    /*Pq.empty(): Checks if the queue is empty and returns its status.*/
    if(Pq.empty()){
        std::cout<< "Queue is Empty";
    }else{
        while(!Pq.empty()){

             /* Pq.top(): Returns a reference to the topmost element of the priority queue.*/
             T1 = Pq.top();
            std::cout <<T1.Priority<<",";

            /*Matching In-CaseSensitive String*/
            if((T1.Permission).compare("Accepted")==0){
                T1.Accepted();
            }else if((T1.Permission).compare("Denied")==0){
                T1.Denied();
            }else{
            std::cout << "No Information about the Task or Incorrect Input";
            }

            /*copy_Pq.pop(): Removes the first element from the priority queue.*/
            Pq.pop();
            std::cout<< "\n\n";
        }
    }
}


int main(){

/*Created four Task and hard coded its value*/
Task T1,T2,T3,T4;

/*Setting priority and permission of tasks*/
T1.Set_Values(14,"Accepted");
T2.Set_Values(40,"Denied");
T3.Set_Values(6,"Denied");
T4.Set_Values(6,"Accepted");


/*Here I have used STL Priority queue as it is the implementation of Heap Data Structure
Parameters: Task -> objects of class
            vector -> used to store object( underlying container)
            CompareClass -> In order to Implement Min. Heap
*/
std::priority_queue <Task ,std::vector<Task>,CompareClass> Pq;

/*1.Each item in the priority queue is associated with a priority.
  2.The item with the lowest priority is the first item to be removed from the queue.
  3.If more than one item has the same priority, then their order in the queue is considered.*/

/*Inserting elements in Queue
  It takes "O(log N)" time to insert*/
Pq.push(T1);
Pq.push(T2);
Pq.push(T3);
Pq.push(T4);

/*Printing content of Priority Queue after insertion*/
Print_Pq(Pq);

/*Deleting data from priority queue
  It takes "O(log N)" time to delete*/
Extract_Data_From_ReadyQueue(Pq);

/*Printing content of Priority Queue after removing all task*/
Print_Pq(Pq);

return 0;
}
