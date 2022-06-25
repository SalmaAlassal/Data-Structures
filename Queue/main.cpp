#include <iostream>
#include "Queue.cpp"
using namespace std;

int main()
{
    Queue<int> q;

    q.push(10); // queue: 10
    q.push(20); //  queue: 10 , 20

    cout << q.front() << ' ' << q.back() << endl; // output: 10 20
    cout << q.size() << endl;                     // print the size of queue -> 2 at this moment

    q.push(30); // queue: 10 , 20 , 30
    q.push(40); // queue: 10 , 20 , 30 , 40
    q.pop();    // delete the first element in the queue -> 10 at this moment

    cout << q.front() << ' ' << q.back() << endl; // output: 20 40
    cout << q.size() << endl;                     // print the size of queue -> 3 at this moment

    while (q.size() != 0) // loop until container is empty
    {
        cout << q.front() << " ";
        q.pop();
    }
    
    // the output of the previous loop is : 20 30 40
}