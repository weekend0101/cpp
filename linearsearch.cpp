#include <iostream>
using namespace std;

void linearSearch(int arr[], int size, int key) {
    bool found = false; 

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) { 
            cout << "Key found at position: " << i + 1 << endl;
            found = true;
            break; 
        }
    }
    if (!found) { 
        cout << "Key not found" << endl;
    }
}

int main() {
    int n, key;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the key to search: ";
    cin >> key;

    linearSearch(arr, n, key);

    return 0;
}














