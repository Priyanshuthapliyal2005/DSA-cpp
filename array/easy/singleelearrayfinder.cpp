#include<iostream>
#include<vector>
using namespace std;

class ArrayManipulator {
public:
    int getSingleElement(vector<int>& arr) {
        int xorr = 0;
        for (int i = 0; i < arr.size(); i++) {
            xorr = xorr ^ arr[i];
        }
        return xorr;
    }
};

int main() {
    // Create an instance of the ArrayManipulator class
    ArrayManipulator manipulator;

    // Example usage
    vector<int> numbers = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int singleElement = manipulator.getSingleElement(numbers);

    cout << "The single element in the array is: " << singleElement << endl;

    return 0;
}
