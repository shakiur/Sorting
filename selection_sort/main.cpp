/*
Find the smallest element using a linear scan and move it to the front. Then, find the second
smallest and move it, again doing a linear scan. Continue doing this until all the elements
are in place. O(n^2).
*/
#include <iostream>

void selectionSort(int*, int);

void display(int*, int);

int main(){
    int arr[5] = {5, 4, 3, 2, 1};

    display(arr, 5);

    selectionSort(arr, 5);

    display(arr, 5);

}

void selectionSort(int* arr, int size){

    for(int i = 0; i < size; ++i){
        
        int low_pos = i;

        // Finds lowest position after 'i'
        for(int j = i; j < size; j++){

            if(arr[j] < arr[low_pos])
                low_pos = j;
        }

        // Swap lowest element with 'i'
        int temp = arr[i];
        arr[i] = arr[low_pos];
        arr[low_pos] = temp;

    }
}

void display(int* arr, int size){
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}