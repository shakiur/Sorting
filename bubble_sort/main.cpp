#include <iostream>

void bubbleSort(int*, int);

void displayArr(int[], int);

int main(){
    
    int arr[5] = { 5, 4, 3, 2, 1 };

    displayArr(arr, 5);
    
    bubbleSort(arr, 5);

    displayArr(arr, 5);

}

void bubbleSort(int* arr, int size){

    for(int i = 0; i < size; ++i){

        if(arr[i] > arr[i + 1]){
            // Swap if 2 elements are out of order
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;

            // Reset to check all pairs
            // Set to -1 because ++i sets it back to 0
            i = -1;
        }

    }
}

void displayArr(int arr[], int size){

    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}