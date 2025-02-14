//Question: https://leetcode.com/problems/product-of-the-last-k-numbers/?envType=daily-question&envId=2025-02-14
//Level: Medium

class ProductOfNumbers {
public:

    vector<int> mult;
    int lastsize = 0;

    ProductOfNumbers() {
        mult.push_back(1);
    }

    void add(int num) {

        if(num != 0) mult.push_back(mult[mult.size() - 1] * num);
        else{
            lastsize = mult.size() - 1;
            mult.resize(0);
            mult.push_back(1);
        }

    }

    int getProduct(int k) {

        if(k >= mult.size()) return 0;
        return mult[mult.size() - 1] / mult[mult.size() - k - 1];

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
