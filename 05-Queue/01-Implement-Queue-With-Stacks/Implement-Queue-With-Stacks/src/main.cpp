#include <iostream>
#include <stack>


class MyQueue {
private:
    std::stack<int> in_stack;
    std::stack<int> out_stack;
public:
    MyQueue() {

    }

    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        if (out_stack.size() == 0) {
            while (in_stack.size()>0)
            {
                int a = in_stack.top();
                out_stack.push(a);
                in_stack.pop();
            }
        }
        int b = out_stack.top();
        out_stack.pop();
        return  b;
    }

    int peek() {
        if (out_stack.size() == 0) {
            while (in_stack.size() > 0)
            {
                int a = in_stack.top();
                out_stack.push(a);
                in_stack.pop();
            }
        }
        return out_stack.top();
    }

    bool empty() {
        return (in_stack.size() == 0 && out_stack.size() == 0);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
