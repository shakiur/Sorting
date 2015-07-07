#include <iostream>

void display(int*, int);

void insertSort(int*, int);

int main(){
    int size = 5;
    int arr[5] = {5, 4, 3, 2, 1};

    display(arr, size);

    insertSort(arr, size);

    display(arr, size);


}

void display(int* arr, int size){
	for(int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

}

void insertSort(int* arr, int size){
	int low_pos;
	int temp;

	for(int i = 1; i < size; i++){

		if(arr[i] < arr[i-1]){
			
			// Find lowest position it can go
			for(int j = (i-1); j >= 0; j--){
				if(arr[i] < arr[j])
					low_pos = j;
			}

			// Shift all numbers forward
			temp = arr[i];

//			std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
//			std::cout << "arr[" << low_pos << "]: " << arr[low_pos] << "\n\n";


			for(int k = i; k > low_pos; k--){
				arr[k] = arr[k-1];
			}

			arr[low_pos] = temp;

		}
	}


}