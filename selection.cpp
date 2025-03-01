#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    int index, j;
    for (int i = 0; i < n - 1; i++) {
        index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}

int main() {
    int arr[1000];
    int n;
    cout << "Enter size of Array";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
