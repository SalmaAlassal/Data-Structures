#include "LinkedList.cpp"
#include <iostream>
using namespace std;

int main()
{

    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(40);

    list.insert(2, 30);
    list.insert(4, 50);

    for (int i = 0; i < list.size(); i++) // 10 20 30 40 50
        cout << list.at(i) << " ";

    cout << endl;

    list.deleteAt(3); // 10 20 30 50
    list.deleteAt(3); // 10 20 30

    list.push_front(99); // 99 10 20 30

    cout << list.front() << endl; // 99
    cout << list.back() << endl;  // 30
    cout << list.at(1) << endl;   // 10

    list.pop_back();  // 99 10 20
    list.pop_front(); // 10 20

    cout << list.front() << endl; // 10
    cout << list.back() << endl;  // 20
    cout << list.at(1) << endl;   // 20

    list.undo(); // 99 10 20
    list.undo(); // 99 10 20 30
    list.undo(); // 10 20 30

    for (int i = 0; i < list.size(); i++) // 10 20 30
        cout << list.at(i) << " ";

    return 0;
}