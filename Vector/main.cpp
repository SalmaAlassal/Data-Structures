#include<iostream>
#include "Vector.cpp"
using namespace std;

int main()
{

    Vector <int> vec;

    for (int i = 0; i < 5; ++i)
    {
        vec.push_back(i);  // 0 1 2 3 4
    }

    cout<< vec.size() <<endl;    // 5
    cout<< vec.capacity() <<endl;    // 10

    cout<< vec.empty() <<endl; // 0 -> False


    cout << vec.front() <<endl; //0
    cout << vec.back() <<endl;  //4


    vec.pop_back();  // 0 1 2 3

    cout << vec.back() <<endl;  //3

    vec.push_back(400); // 0 1 2 3 400

    cout << vec.back() <<endl;  //400

    vec.insert(2,999); // 0 1 999  2 3 400

    while( vec.size()!= 0 )
    {
        cout<< vec.back()<<" ";
        vec.pop_back();
    }
    // 400 3 2 999 1 0

    cout<<endl;

    Vector <int> vec2(5);

    for (int i = 0; i < 5; ++i)
    {
        vec2.push_back(i*2);  //0 2 4 6 8
    }

    cout<<vec2.size()<<endl; //5
    cout<< vec2.capacity() <<endl;    // 5
    vec2.clear();
    cout<<vec2.size()<<endl; //0

}
