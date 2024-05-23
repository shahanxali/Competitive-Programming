//Question: https://leetcode.com/problems/min-stack/
//Level: Medium

class MinStack {
private:
    vector<int> stacki;

public:
    MinStack() {

    }
    
    void push(int val) {
        stacki.push_back(val);
    }
    
    void pop() {
        if (!stacki.empty()) {
            stacki.pop_back();
        }
    }
    
    int top() {
        if (!stacki.empty()) {
            return stacki.back();
        }
        return -1; 
    }
    
    int getMin() {
        if (!stacki.empty()) {
            return *min_element(stacki.begin(), stacki.end());
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */