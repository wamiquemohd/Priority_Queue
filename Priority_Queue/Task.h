#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED
#include<iostream>
#include<queue>

class Task{

public:
    int Priority;
    std::string Permission;

public:
    void Set_Values(int Priority,std::string Permission);
   /*Created two functions as given in the problem statement for Permission Statements*/
    void Accepted();
    void Denied();
};


 void Task::Accepted(){
    std::cout<< "Access is granted";
}
void Task::Denied(){
    std::cout<< "Access is denied";
}
/*Setting values of Tasks*/
void Task::Set_Values(int Priority,std::string Permission){
    this->Priority= Priority;
    this->Permission =Permission;
}


/*Operator Overloading for Min Heap. Thus, lowest priority task is placed at top */
class CompareClass {
    public:
        bool operator()(const Task &p1, const Task &p2)
{
    return p1.Priority > p2.Priority;
}

};



#endif // TASK_H_INCLUDED
