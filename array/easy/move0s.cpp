#include <iostream>
#include <vector>

void move(std::vector<int>& arr) {
    int i, j;
    j = -1;

    for (i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }
    for (i = j + 1; i < arr.size(); i++) {
        if (arr[i] != 0) {
            std::swap(arr[i], arr[j]);
            j++;
        }
    }
}
void swap(int a ,int b){
    int temp=a;
    a=b;
    b=temp;
}

int main() {
    // Test your move function here
    std::vector<int> arr = {0, 2,3,6,0,-6, 0, 4, 0, 6, 8};
    move(arr);

    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}
