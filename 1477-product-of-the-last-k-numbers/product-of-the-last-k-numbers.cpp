
class ProductOfNumbers {
public:
    vector<int> pref;
    int lastZero = -1;  // Position of the last zero
    int index = 0;

    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            lastZero = index;  // Update the last zero position
            pref.push_back(1);  // Push 1 to reset the product
        } else {
            if (index == 0) {
                pref.push_back(num);
            } else {
                pref.push_back(pref.back() * num);
            }
        }
        index++;
    }

    int getProduct(int k) {
        // Check if the last zero is within the last `k` elements
        if (lastZero >= index - k) {
            return 0;
        }

        // Calculate the product using prefix products
        int tot = pref.back();
        int divide = (index - k - 1 >= 0) ? pref[index - k - 1] : 1;
        return tot / divide;
    }
};
