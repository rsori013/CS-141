#include <iostream>
#include <algorithm>
using namespace std;


// for this one we have to implement a mergesort but with 
//with a twist, so basically the problem is that we want to 
//sort the students and everytime we divide the 2 arrays
// we need to make sure that all the numbers in the array will 
// equal so no one feels bad about their grades
// the total is the total of what is being added to make it look fair.

// example 
//first input is the total of the students
// 4
// 3
// 5
// 2
// 1
// output is the answer>> for this one its 7.



void mergeArr(int *rightarr, int *leftarr, int *array, int rsize, int lsize,int &total) {
    int i = 0, right = 0, left = 0;

    while (right < rsize && left < lsize) {
        if (rightarr[right] < leftarr[left]) {
            array[i++] = rightarr[right++];
        } else {
            array[i++] = leftarr[left++];
        }
    }
    while (right < rsize) {
        array[i++] = rightarr[right++];
    }
    while (left < lsize) {
        array[i++] = leftarr[left++];
    }
}

void mergeSort(int *array, int arraysize, int &total) {
    int result =0;
    if (arraysize> 2) { // if the array  size is more than 1 we keep going
        int rs = arraysize / 2;   // to get the half of the size of that array for the right
        int ls = arraysize - rs;  //to get the half of the size for the left array
        int rightarr[rs], leftarr[ls];

        for (int i = 0; i < rs; i++) {    // we assigning the value from array to the right array here
            rightarr[i] = array[i];
        }
       // cout << endl;
        // cout << "THE LIST OF NUMBERS IN THE RIGHT ARRAY: " ;
        //  for (int i = 0; i < rs; i++){
        // cout << rightarr[i] << ", ";
        // }


        *min_element(rightarr, rightarr + rs);   // we are getting the max and min of that array
        *max_element(array, array + rs);
         result = *max_element(array, array + rs) -*min_element(rightarr, rightarr + rs);  // we subtract the max and min to get the difference
         total = total + result;
        //cout << " MIN: " << *min_element(rightarr, rightarr + rs) << " MAX: " << *max_element(array, array + rs) << " RESULTS:" << result << " total " << total<< endl;


        for (int i = rs; i < arraysize; i++) {  // we getting the other half for the left arrray here 
            leftarr[i - rs] = array[i];
        }
        //cout << endl;
        // cout << "THE LIST OF NUMBERS IN THE LEFT ARRAY: "  ;
        //  for (int i = 0; i < ls; i++){
        // cout << leftarr[i] << ", ";
        //  }
        *min_element(leftarr, leftarr + arraysize);   //samme process get the min and max 
        *max_element(leftarr, leftarr + arraysize);
        
        result = *max_element(leftarr, leftarr + ls) -*min_element(leftarr, leftarr + ls);  // subtract the two blah balah
        total = total + result;
        //cout << "MIN: " << *min_element(leftarr, leftarr + ls) << " MAX: " << *max_element(leftarr, leftarr + ls) << " RESULTS:" << result << " total " << total<< endl;
        
        
        mergeSort(rightarr, rs,total);
        mergeSort(leftarr, ls,total);
        mergeArr(rightarr, leftarr, array, rs, ls,total);
        
    }
        // *min_element(array, array + (arraysize));        // for the whole array we get the different when the whole array is good
        // *max_element(array, array + (arraysize));
        // result = *max_element(array, array + (arraysize)) - *min_element(array, array +(arraysize));
        // total += result;
    //return total;
}

int main() {
   int n;
   static int total=0;
   //cout << "Enter the number of elements: ";
   cin >> n;
   int array[n];     //create an array with given number of elements
   //cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> array[i];
   }
    
    mergeSort(array, n,total);
    // for (int i = 0; i < n; i++)
    //     cout << array[i] << " ";
    int lastarraydiff =0;
    *min_element(array, array + (n));        // for the whole array we get the different when the whole array is good
    *max_element(array, array + (n));
    lastarraydiff = *max_element(array, array + (n)) - *min_element(array, array +(n));
    total += lastarraydiff;
    
    cout <<  total;
}
