//Question: https://leetcode.com/problems/design-a-stack-with-increment-operation/?envType=daily-question&envId=2024-09-30
//Level: Medium

class CustomStack {
public:

    int n;
    vector<int> stack;

    CustomStack(int maxSize) {
        n = maxSize;
    }

    void push(int x) {
        if(stack.size() < n){
            stack.push_back(x);
            return;
        }

        return;
    }

    int pop() {
        if(stack.empty()) return -1;
        stack.pop_back();
        return *stack.end();
    }

    void increment(int k, int val) {
        for(int i = 0; i < (min(k, int(stack.size()))); i++){
            stack[i] += val;
        }
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
