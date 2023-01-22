// we have a lot of notebooks bags and we need to  bring it all in campus
// and we can only merge two of them a time. 
// After two bags are merged, with size x and y respectively, they become one bag 
// of notebooks with size x+y and we need to keep on doing this 
// till there is just one bag of notebooks

// The four bags contain 3,8,1 and 6 notebooks respectively. In the optimal solution, We  should first merge 1 and 3. 
// Before merging she counts 1 notebooks and 3 notebooks in the two bags. After merging she counts the number of notebooks 
// in the new bag, which is 4. In total she counts 8 notebooks in this merge.
// Example:
// Inputs:
// 4
// 3
// 8
// 1
// 6
//  output = 64
// In the second merge, she should merge the bags of size 6 and 4 (achieved by the first merge). Before merging she counts 6 
// notebooks and 4 notebooks in the two bags. After merging she counts the number of notebooks in the new bag, which is 10. In total she counts 20 notebooks in this merge.
// In the third merge, she should merge the bags of size 8 and 10 (achieved by the second merge). Before merging she counts 8
//  notebooks and 10 notebooks in the two bags. After merging she counts the number of notebooks in the new bag, which is 18. In total she counts 36 notebooks in this merge.
// Then all of the notebooks are in one bag of size 18 . She made in total 8+20+36=64 counts. This is the optimal solution.


#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    int amount,input,merge;
    cin >> amount;
    list<int> Huffman;
    
    for(int i=0; i < amount; i++){
        cin>>input;
        Huffman.push_back(input);
    }
    int total=0;
    for(int i = 0; i < amount; i++){
       
        if(Huffman.size() <= 1){
            cout << total << endl;
            break;
        }
        else{
        Huffman.sort();
        int one = Huffman.front();
        //cout << "one " << one << endl;
        Huffman.pop_front();
        int two = Huffman.front();
       // cout << "two " << two << endl;
        Huffman.pop_front();
        merge = (one + two);
        //cout << "merge " << merge << endl;
        Huffman.push_back(merge);
        merge = (one + two)*2;
        total = total + merge;
        //cout << "total " << total << endl;
        //cout << "size" << Huffman.size() << endl;
        
        }
        
        
        
        
    }
   cout<< total;
    

    return 0;
}