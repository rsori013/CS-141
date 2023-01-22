// goal is to sort the the houses and list all its names
// example inputs 
// input
// 6
// Harry Gryffindor
// Hannah Hufflepuff
// Luna Ravenclaw
// Draco Slytherin
// Hermione Gryffindor
// Ron Gryffindor
// outputCopy
// Gryffindor
// Harry
// Hermione
// Ron
// Hufflepuff
// Hannah
// Ravenclaw
// Luna
// Slytherin
// Draco
#include <iostream>
#include <map>
#include <iterator>
using namespace std;
 
int main(){
 
 
    int num;
    cin >> num;
    map<string,string> list;
    string name;
    string house;
    for(int i =0; i < num; i++ ){
        cin >> name >> house;
        list.insert({name,house});
    }
 
    map<string,string> :: iterator it;
    cout <<"Gryffindor" << endl;
    for (it = list.begin();it != list.end(); it++){
        if(it->second == "Gryffindor"){
            cout << it->first << endl;
        }
    }
     cout <<"Hufflepuff" << endl;
     for (it = list.begin();it != list.end(); it++){
        if(it->second == "Hufflepuff"){
            cout << it->first << endl;
        }
    }
    cout << "Ravenclaw" << endl;
     for (it = list.begin();it != list.end(); it++){
        if(it->second == "Ravenclaw"){
            cout << it->first << endl;
        }
    }
     cout << "Slytherin" << endl;
     for (it = list.begin();it != list.end(); it++){
        if(it->second == "Slytherin"){
            cout << it->first << endl;
        }
    }
    //list["harry"]= "potter";
}
