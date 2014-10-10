#include <iostream>

using namespace std;

void display(int *, int);

void mergeSort(int*, int*, int, int);
void merge(int*, int*, int, int, int, int);

void bubbleSort(int*, int);

void selectionSort(int*, int, int);

int main(){
	int arr_size = 4;

	int * arr = new int[arr_size];
	arr[0] = 7;
	arr[1] = 2;
	arr[2] = 15;
	arr[3] = 9;

	int * sort_arr = new int[arr_size];

	//mergeSort(arr, sort_arr, 0, arr_size-1);
	//bubbleSort(arr, arr_size);
	//selectionSort(arr, arr_size, 0);

}

void display(int * arr, int size) {
	for(int i = 0; i < size; i++){
		cout << arr[i] << endl;
	}
}

void mergeSort(int * arr, int * sort_arr, int start, int end){

	if(end > start){

		int middle = ((end-start)/2) + start;

		mergeSort(arr, sort_arr, start, middle);
		mergeSort(arr, sort_arr, middle + 1,end);

		merge(arr, sort_arr, start, middle, middle + 1, end);

	}

}

void merge(	int * arr, int * sort_arr,
			int first_start, int first_end,
			int second_start, int second_end) {

	// Used to know where to copy
	int orig_first_start = first_start;

	int sort_arr_pos = 0;
	int sort_arr_len = (second_end - first_start)+1;

	sort_arr = new int[sort_arr_len];

	while(sort_arr_pos < sort_arr_len) {

		if(first_start <= first_end && second_start <= second_end) {

			if(arr[first_start] < arr[second_start]){
				sort_arr[sort_arr_pos] = arr[first_start];
				first_start++;
			}
			else{
				sort_arr[sort_arr_pos] = arr[second_start];
				second_start++;
			}

		}
		else if(first_start > first_end && second_start <= second_end) {
			sort_arr[sort_arr_pos] = arr[second_start];
			second_start++;
		}
		else if(second_start > second_end && first_start <= first_end){
			sort_arr[sort_arr_pos] = arr[first_start];
			first_start++;
		}
		sort_arr_pos++;
	}

	// Copy sorted array into original array
	copy(sort_arr, sort_arr + sort_arr_len, arr + orig_first_start);
	
}

void bubbleSort(int * arr, int size){

	int i = 0;

	while(i < (size-1)) {

		if(arr[i] > arr[i+1]){

			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			i=0;

		}
		i++;

	}
}

void selectionSort(int * arr, int size, int start) {

	if(start < size) {

		int small_pos = start;

		// Find smallest element
		for(int i = start+1; i < size; i++) {
			if(arr[i] < arr[small_pos]){
				small_pos = i;
			}
		}


		// Swap smallest
		int temp = arr[start];
		arr[start] = arr[small_pos];
		arr[small_pos] = temp;

		// Sort rest of array
		selectionSort(arr, size, ++start);
	}
}