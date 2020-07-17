#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class CQueue {
private:
    stack<int> buff, out;
public:
    CQueue() = default;
    
    void appendTail(int value) {
        buff.push(value);
    }
    
    int deleteHead() {
        if (out.empty()) {
            while (!buff.empty()) {
                out.push(buff.top());
                buff.pop();
            }
        }
        if (!out.empty()) {
            int ret = out.top();
            out.pop();
            return ret;
        }
        return -1;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */