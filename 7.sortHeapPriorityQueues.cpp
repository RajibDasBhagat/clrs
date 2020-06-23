// Note that by default C++ creates a max-heap
// for priority queue
#include <iostream>
#include <queue>

using namespace std;

void display(priority_queue <int> arr){
    priority_queue <int> g = arr;
    while (!g.empty()){
        cout << g.top()<<" ";
        g.pop();
    }
    cout << '\n';
}

int main ()
{
    priority_queue <int> arr;
    arr.push(10);
    display(arr);
    arr.push(30);
    display(arr);
    arr.push(20);
    display(arr);
    arr.push(5);
    display(arr);
    arr.push(1);
    display(arr);

    cout << "\nsize: " << arr.size();
    cout << "\ntop: " << arr.top();

    cout << "\npop: \n";
    arr.pop();
    display(arr);
    arr.pop();
    display(arr);
    arr.pop();
    display(arr);

    return 0;
}
