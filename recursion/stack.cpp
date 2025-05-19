#include <iostream>
#include <stack>
using namespace std;

// Insert element at the bottom of stack
void insertBottom(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }

    int top = st.top();
    st.pop();
    insertBottom(st, val);
    st.push(top);
}

// Reverse the stack using recursion
void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int top = st.top();
    st.pop();
    reverseStack(st);
    insertBottom(st, top);
}

// Print stack from top to bottom
void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original: ";
    printStack(st);

    reverseStack(st);

    cout << "Reversed: ";
    printStack(st);

    return 0;
}