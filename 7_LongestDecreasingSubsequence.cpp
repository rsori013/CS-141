// This is a dp problem that involves Longest decreesing subsquence.
// first input will be theh number of digits and then we will input th
// digits and then we will find the logest decreasing subsequence

// example: 
//input: 
// 9
// 10 5 4 7 9 6 3 8 2

// output : 5 -- will be the longest subsequence
// 10,7,6,3,2

#include <iostream>
#include <algorithm>
using namespace std;
 
void longestIncreasingSubsequence(int arr[], int n) {
   int freqHolder[n] = {0}; // setting everything in the array 0;
   freqHolder[0] = 1;    
   for (int i = 1; i < n; i++) {    
      for (int j = 0; j < i; j++) {    
         if (arr[j] > arr[i] && freqHolder[j] > freqHolder[i])
            freqHolder[i] = freqHolder[j];
      }
      freqHolder[i]++; //add arr[i]
   }
   // checking what are the frequencies
//   for (int i = 0; i<n; i++) {
//       cout << freqHolder[i] << " ";
//   }
   cout << *max_element(freqHolder,freqHolder + n);
    
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
   
   longestIncreasingSubsequence(arr, numInput);
   return 0;
}
 
