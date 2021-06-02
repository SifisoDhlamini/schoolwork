#include <iostream>
using namespace std;

template<typename T>
T *sort(T *array, int n)
{
   T *arr2 = new T[n];
    for(int i = 0; i < n; i++){        
        arr2[i] = array[i];
    }
    
    for(int i = 0; i < n - 1; i++){        
        for(int j = i + 1; j < n; j++){
            T temp;
            if(array[i] > array[j]){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    
    return arr2;
}

int main(int argc, char **argv)
{
	int arr1[] = {7, 9, 1, 0, 4, 9, 12, 3};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int *arr2 = new int[n];
    
    arr2 = sort(arr1, n);
    
    cout<<"in main:"<<endl;
    for(int i = 0; i < n; i++){
        cout<<arr2[i]<<endl;
    }
    
    
	return 0;
}
