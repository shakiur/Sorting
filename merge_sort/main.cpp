/*
Sort each pair of elements. Then, sort every four elements by merging every two pairs. Then,
sort every 8 elements, etc. O(n log n) expected and worst case.
*/
#include <iostream>

void mergeSort(int*, int, int);

void merge(int*, int, int, int, int);

void display(int*, int, int);

int main(){
    int begin = 0;
    int end = 4;
    int arr[5] = {5, 4, 3, 2, 1};

    std::cout << "Initial Array: ";
    display(arr, begin, end);
    std::cout << std::endl;

    mergeSort(arr, begin, end);

    std::cout << "Sorted Array: ";
    display(arr, begin, end);
    std::cout << std::endl;
}

void mergeSort(int* arr, int begin, int end){
    if(end > begin){

        int middle = (begin + end)/2;

        mergeSort(arr, begin, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, begin, middle, middle + 1, end);
    }
}

void merge(int* arr, int beg1, int end1, int beg2, int end2){

    
    // Debug Info
    std::cout << "arr[" << beg1 << ".." << end1 << "]: ";
    display(arr, beg1, end1);

    std::cout << "arr[" << beg2 << ".." << end2 << "]: ";
    display(arr, beg2, end2);

    std::cout << std::endl;
    

    int copy_bgn = beg1;
    int pos = 0;
    int new_size = (end2 - beg1) + 1;

    int * new_arr = new int[new_size];
    
    // Go through both arrays and copy into new array
    while(pos < new_size){
        // If both arr's are active, find lowest 1 between btoh
        if(beg1 <= end1 && beg2 <= end2){
            if(arr[beg1] < arr[beg2]){
                new_arr[pos] = arr[beg1];
                ++beg1;
            }
            else{
                new_arr[pos] = arr[beg2];
                ++beg2;
            }
        }
        // Else if arr1 has been visited completely, only pull from arr2
        else if(beg1 > end1 && beg2 <= end2){
            new_arr[pos] = arr[beg2];
            ++beg2;
        }
        // Else arr2 has been visited completely, only pull from arr1
        else{
            new_arr[pos] = arr[beg1];
            ++beg1;
        }
        ++pos;
    }

    std::cout << "New Array: ";
    display(new_arr, 0, new_size - 1);
    std::cout << std::endl;

    // Copies new "mini-sorted" array into main array
    std::copy(new_arr, new_arr + new_size, arr + copy_bgn);

}

void display(int* arr, int beg, int size){
    for(int i = beg; i <= size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}