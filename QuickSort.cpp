#include<iostream>
#include<stack>
#include<cstdlib>
#include<ctime>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low -1;
    for (int j=low; j<high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

int randomized_partition(int arr[], int low, int high) {
    int r = low + rand()%(high-low+1);
    swap(arr[r], arr[high]);
    return partition(arr, low, high);
}

void quickSort(int arr[], int n) {
    stack<pair<int,int>> s;
    s.push({0,n-1});
    while (!s.empty()) {
        int low = s.top().first;
        int high = s.top().second;
        s.pop();
        if (low < high) {
            int p = randomized_partition(arr, low, high);
            if (low < p-1) s.push({low,p-1});
            if (p+1<high) s.push({p+1,high});
        }
    }
}

int main() {
    int n;
    cout<<"Enter no. of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : "<<endl;
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    quickSort(arr,n);
    cout<<"Sorted array is : "<<endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
        
    return 0;
}
