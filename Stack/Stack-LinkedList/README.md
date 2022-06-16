# Stack Implementaion using a LinkedList in C++

Each node contains data and a link to the next node (The next element after the top element). This approach is achieved by using:
 - `Node` class which store the data and a pointer to the next stack node.
 - `Stack` class which has a pointer to the top of the stack.

![Explanation](StackExplanation.png)

## Time complexity

| Function  | Description |
|-----------|------|
| `size()`  | O(1) |
| `empty()` | O(1) |
| `top()`   | O(1) |
| `push(x)` | O(1) |
| `pop()`   | O(1) |
| `clear()` | O(n) |


### Members

| Member   | Description |
|----------|-------------|
|`data`    | Stores data. |
|`next`    | Points to the next stack node. |
|`head`    | Points to the top of the stack. |
|`elements`| Holds the number of items in the stack. |


### Constructors & Destructor

| Constructor / Destructor | Description |
|--------------------------|-------------|
| Node(value)              | Stores the value of the node and set the next pointer to NULL. |
| Stack(void)              | Initially set head pointer to NULL and the number of elements to 0. |
| ~Stack(void)             | Deleting all nodes of the stack one by one. |
 
 
## Public Functions

| Function | Description |
|----------|------|
| `size()` | Returns the size of the stack. |
| `empty()`| Returns whether the stack is empty. |
| `top()`  | Returns the top most element of the stack.|
| `push(x)`| Adds the element ‘x’ at the top of the stack.|
| `pop()`  | Deletes the top most element of the stack.|
| `clear()`| Deleting all nodes of the stack one by one. |