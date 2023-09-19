#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quicksort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr;
    int i;
    cout << "Enter the elements of the array: ";
    for (i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<int> sortedArr = quicksort(arr); // Store the sorted result
    cout << "Sorted merged array:";
    for (i = 0; i < n; i++) {
        cout << sortedArr[i] << " ";
    }
    return 0;
}
