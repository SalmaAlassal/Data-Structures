#include<iostream>
#include "ArrayList.cpp"
using namespace std;

int main()
{

    ArrayList<int> list;

    for (int i = 0; i < 5; ++i)
    {
        list.push_back(i);  //0 1 2 3 4
    }

    cout<< list.size() <<endl;    //5
    cout<< list.empty() <<endl; //0 -> False

    cout << list.front() <<endl; //0
    cout << list.back() <<endl;  //4


    list.pop_back();  // 0 1 2 3

    cout << list.back() <<endl;  //3

    list.push_back(400); // 0 1 2 3 400

    cout << list.back() <<endl;  //400

    list.pop_front(); //  1 2 3 400

    cout <<  list.front() <<endl; // 1


    list.push_front(900); // 900 1 2 3 400
    list.insert(2,999); // 900 1 999  2 3 400

    while( list.size()!=0 )
    {
        cout<< list.front()<<" ";
        list.pop_front();
    }

    cout<<endl;

    ArrayList<int> list2;

    for (int i = 0; i < 5; ++i)
    {
        list2.push_back(i*2);  //0 2 4 6 8
    }

    cout<<list2.size()<<endl; //5
    list2.clear();
    cout<<list2.size()<<endl; //0

}
