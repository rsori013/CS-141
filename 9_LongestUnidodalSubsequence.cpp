
//For example, a sequence of 1, 2, 3, 4, 3, 2, 1 is unimodal, but 4, 3, 2, 1 is not.
//Examples:
//input:
// 9
// 1 5 4 7 9 6 3 8 2

// output = 7;
#include <iostream>
#include <algorithm>
using namespace std;
 
void longestUnimodalSubsequence(int arr[], int n)
{   //int size = n;
    int decreasing[n];
    int increasing[n];
    int unimodal[n];
    
    
    //initializing everything in arrays to 1 
    for (int i = 0; i < n; i++){
        decreasing[i] = 1; 
        increasing[i] = 1;
    }
    
   
    //LIS
     for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j] && increasing[i] < increasing[j] + 1)
                increasing[i] = increasing[j] + 1;
        }
     }
     //LDS
      for (int i = n-2; i >= 0; i--){
        for (int j = n-1; j > i; j--){
         if (arr[i] > arr[j] && decreasing[i] < decreasing[j] + 1)
            decreasing[i] = decreasing[j] + 1;
        }
      }
     unimodal[0]=0;
     for (int i = 1; i < n; i++) {
         unimodal[i]=  increasing[i] + decreasing[i] - 1;
         //cout << unimodal[i] << " ";
     }
     //cout << endl;
    cout << *max_element(unimodal,unimodal + n); // getting the max in array unimodal
    
}
int main() {
   
   int numInput;
   cin >> numInput; // first line of input
   
   int arr[numInput] ;
   for (int i = 0; i < numInput; i++){
       int input;
       cin >> input;
       arr[i]= input;
   }// put all in input in the array
   
  longestUnimodalSubsequence(arr, numInput);
   return 0;
}