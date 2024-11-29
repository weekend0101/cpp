#include <iostream>
using namespace std;

void binarySearch(int arr[], int size, int key) {
    int first = 0;                 int last = size - 1;        
    bool found = false;         
    while (first <= last) {
        int mid = (first + last) / 2;          
        if (arr[mid] == key) {         
            cout << "Key found at position: " << mid + 1 << endl;
            found = true;             
            break;                   
          else if (arr[mid] < key) {      
            first = mid + 1;           
        } 
        else {                         
            last = mid - 1;            
        }
    }

    if (!found) {          cout << "Key not found" << endl;
    }
}

int main() {
    int n, key;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the sorted elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the key to search: ";
    cin >> key;

    binarySearch(arr, n, key);

    return 0;
}
