// for this one we need to the situation is that there will be a voting and we need to win
// the first number in the input will be the number of group there will be and after that
// there will be that many inputs and what is in that input is the number of of people in there
// to win a grouup we need to get the majority win of that group
// lets say a group have a number of  10 people then we need to get 6 people from that group 
// let say there are 10 groups therefore we need to win atleast 6 groups to win
// example: 
// intput: 
// 3
// 5
// 7
// 5
// output: 6
// so for this one there are 3 groups therefore we need to win two grups and then in order to win the two groups 
// I need to get the ones with the lowest one and then get the minimum amount of people from that group to piick me
// in this example we will want the group with 5 and 5 people. To get the win from that we need to get 3 from each.
// therfore the answer is 6.
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void rearrangeArray(int array[], int n)
{
    // Sorting the array elements
    sort(array, array + n);
 
    int tempArr[n]; // To store modified array
 
    // Adding numbers from sorted array to
    // new array accordingly
    int ArrIndex = 0;
 
    // Traverse from begin and end simultaneously
    for (int i = 0, j = n - 1; i <= n / 2 || j > n / 2;
         i++, j--) {
        tempArr[ArrIndex] = array[i];
        ArrIndex++;
        tempArr[ArrIndex] = array[j];
        ArrIndex++;
    }
 
    // Modifying original array
    for (int i = 0; i < n; i++)
        array[i] = tempArr[i];
}

int main()
{   
    int num,input;
    cout << "Enter the Number of Departments: ";
    cin >> num;
    
    int array[num];
    
    for ( int i = 0; i < num; i++ ){
        cin >> input;
        array[i]= input;
    }
    
    // for (int i = 0; i< num; i++){
    //     cout << array[i] << endl;
    // }

    rearrangeArray(array, num);
    
    for (int i = 0; i < num; i++){
        cout << array[i] << " ";
    }
    int size;
    size = num/2;
    cout << size;
    
    

    return 0;
}
