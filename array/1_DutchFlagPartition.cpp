#include <iostream>
#include <vector>
using namespace std;

void DutchFlagPartition(int pivot_index, vector<int> &A) {  // TC = O(n^2)
    int pivot = A[pivot_index];

    // First pass: group elements smaller than pivot.
    int smaller = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] < pivot) {
            swap(A[i], A[smaller]);
            smaller++;
        }
    }

    // Second pass: group elements larger than pivot.
    int larger = A.size() - 1;
    for(int i = A.size() - 1; i >= 0; i--) {
        if(A[i] > pivot) {
            swap(A[i], A[larger]);
            larger--;
        }
    }
}

void DutchFlagPartition2(int pivot_index, vector<int> &A) {  // TC = O(n)
    int pivot = A[pivot_index];
    int smaller = 0;

    // First Pass: group elements smaller than pivot.
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] < pivot)
        {
            swap(A[i], A[smaller++]);
        }
    }

    // Second Pass: group elements larger than pivot.
    int larger = A.size() - 1;
    for(int i = A.size() - 1; i >= 0; i--)
    {
        if(A[i] > pivot)
        {
            swap(A[i], A[larger--]);
        }
    }
}

void DutchFlagPartition3(int pivot_index, vector<int> &A) {
    int pivot = A[pivot_index], smaller = 0, equal = 0, larger = A.size();
    while(equal < larger)
    {
        if(A[equal] < pivot)
        {
            swap(A[equal++], A[smaller++]);
        }
        else if(A[equal] == pivot)
        {
            equal++;
        }
        else {  // A[equal] < pivot
            swap(A[equal], A[--larger]);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int pivot_index;
    cout << "Enter the pivot index: ";
    cin >> pivot_index;

    DutchFlagPartition3(pivot_index, A);

    cout << "Partitioned array: ";
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
