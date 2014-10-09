#include <iostream>

using namespace std;

void mergeSort(int*, int*, int, int);
void merge(int*, int*, int, int, int, int);

int main(){
	int arr_size = 4;
	int * arr = new int[arr_size];
	arr[0] = 7;
	arr[1] = 2;
	arr[2] = 15;
	arr[3] = 9;

	int * sort_arr = new int[arr_size];

	//copy(arr,arr+4,sort_arr);

	mergeSort(arr, sort_arr, 0, arr_size-1);

}

void mergeSort(int * arr, int * sort_arr, int start, int end){

	if(end > start){

		int middle = ((end-start)/2) + start;

		//cout << "END: " << end << endl;
		//cout << "STR: " << start << endl;
		//cout << "MID: " << middle << endl << endl;

		mergeSort(arr,sort_arr, start,middle);
		mergeSort(arr,sort_arr, middle+1,end);

		merge(arr, sort_arr, start,middle,middle+1,end);

	}

}

void merge(	int * arr, int * sort_arr,
			int first_start, int first_end,
			int second_start, int second_end) {

	cout << "1 STR: " << first_start << endl;
	cout << "1 END: " << first_end << endl;

	cout << "2 STR: " << second_start << endl;
	cout << "2 END: " << second_end << endl << endl;

	int sort_arr_pos = 0;
	int sort_arr_len = (second_end - first_start)+1;

	sort_arr = new int[sort_arr_len];

	while(sort_arr_pos < sort_arr_len) {

		if(	first_start <= first_end 
			&& 
			arr[first_start] < arr[second_start]) 
		{
			//sort_arr[sort_arr_pos] = arr[first_start];
			cout << "First " << first_start << ": " << arr[first_start] << endl;
			first_start++;
		}
		else if(	second_start <= second_end
					&&
					arr[second_start] < arr[first_start])
		{
			//sort_arr[sort_arr_pos] = arr[second_start];
			cout << "Second " << second_start << ": " << arr[second_start] << endl;
			second_start++;
		}
		cout << endl;
		sort_arr_pos++;
	}
}