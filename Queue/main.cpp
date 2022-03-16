#include <iostream>
#include "Queue.cpp"
using namespace std;

struct tasks
{
    string name;
    int ID;
};

int main()
{

    Queue <tasks>q;
    tasks task;
    int option;
    bool exit = false;
    cout << "************Welcome to task manager************" << endl;
    while(!exit)
    {
        cout<<endl;
        cout << "To add new task press 1 " << endl;
        cout << "To remove a task press 2 " <<endl;
        cout << "To exit press 3 "<< endl;

        cin >> option;

        switch( option )
        {
          case 1 :
          {
            cout << "Enter taks ID: " << endl;
            cin >> task.ID;
            cout << "Enter task name: " << endl;
            cin >> task.name;
            q.push(task);
            break;
          }
          case 2:
          {
            task = q.front();
            cout<<"------------------"<<endl;
            cout << "Taks ID : " <<task.ID<< endl;
            cout << "Task name : " << task.name<<endl;
            cout<<"------------------"<<endl;

            q.pop();
            break;
          }
          case 3:
          {

            exit = true;
            cout<<"************ Exit ************"<<endl;
            break;
          }
        }

    }
}
