# Vector Implementation using a Dynamic Array

 - Vectors are used to store elements of similar data types. However, unlike arrays, the size of a vector can grow dynamically.

 - Vectors use contiguous memory. All elements in the vector are located next to each other in the same memory space, this is why retrieving an element is **so fast**.


## Time Complexity

|     Function    | Complexity  |
|-----------------|-------------|
| `size()`        |    O(1)     |
| `capacity()`    |    O(1)     |
| `empty()`       |    O(1)     |
| `expand()`      |    O(n)     |
| `insert(pos, x)`|    O(n)     |
| `push_back(x)`  |    O(n)     |
| `pop_back()`    |    O(1)     |
| `back()`        |    O(1)     |
| `front()`       |    O(1)     |
| `clear()`       |    O(1)     |

## Members

| Member   | Description |
|----------|-------------|
|`arr`     | Generic container to store data.|
|`elements`| Holds the number of items in the array.|
|`capacity`| Holds the array size and Increases the size of new array by twice when the array gets full.|


## Constructors & Destructor

| Constructor / Destructor | Description |
|--------------------------|-------------|
| `Vector()`               | Allocates the memory for an array of size 10.|
| `Vector(capacity)`       | Allocates the memory for an array of size selected by the user.|
| `~Vector()`              | Releases memory using by the array before the class instance is destroyed.|
 

## Private Functions

| Function | Description |
|----------|-------------|
|`expand()`| Doubles the vector by twice and copy the previous elements to a new array.|


## Public Functions

|    Function     | Description |
|-----------------|-------------|
| `size()`        | Returns the number of elements in the vector. |
| `capacity()`    | Returns the size of the storage space currently allocated to the vector.|
| `empty()`       | Returns whether the vector is empty(1) or not(0). |
| `insert(pos, x)`| Inserts a new element with the value 'x' in the vector before the element at a specified position, and increases size of the list by 1.|
| `push_back(x)`  | Adds a new element ‘x’ at the end of the vector, and increases size of the list by 1.|
| `pop_back()`    | Removes the first element of the vector, and reduces size of the list by 1.|
| `back()`        | Returns the value of the last element in the vector.|
| `front()`       | Returns the value of the first element in the vector.|
| `clear()`       | Removes all the elements of the vector container, thus making its size 0.|


## Example 

```cpp
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
```
