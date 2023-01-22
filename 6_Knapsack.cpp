// first input is the weight budget and the nxt one is the number of items
//The next n lines each contains 2 integers. 
// weight and its value
//output will be the maximum value we can get with out weight limit.
//Example:
// input:
// 20 5
// 6 3
// 7 2
// 14 4
// 3 1
// 10 5

// output : 9 --- therefore 9 is the max value we can get with
// a weight limit of 20.

#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int weightLimit, numObject;
    cin >> weightLimit >> numObject;
    
    int weights,values;
    float totalValue=0;
   // cout << "weightLimit: " << weightLimit << endl;
    //cout << "numObject: " << numObject << endl;
    
    int weight[numObject];
    int value[numObject];
    float ratio[numObject];
    for (int i = 0; i < numObject; i++){
        cin >> weights >> values;
        weight[i]= weights;
        value[i]=values;
        
        totalValue = (float)values/weights;
        ratio[i]= totalValue;
    }
    // cout << "weights" << endl;
    // for (int i = 0; i <numObject; i++){
    //     cout << weight[i] << " ";
    // }
    // cout << "values" << endl;
    // for (int i = 0; i< numObject; i++){
    //     cout << value[i] << " ";
    // }
    // cout << "ratios" << endl;
    // for (int i = 0;i< numObject; i++){
    //     cout << ratio[i] << " ";
    // }
    int index,total, counter =0;
    
    for(int i = 0; i < numObject;i++){
        for(int j = 0; j < numObject;i++){
            float max = *max_element(ratio, ratio +numObject);
            //cout << max;
            counter++;
            if (ratio[j]==max){
            index = counter;
            ratio[j]= 0;
            }
        }
        weightLimit -= weight[index];
        
        if ( weightLimit >= 0){
            total += value[index];
        }
        
    }
    return 0;
}
