// need to visit from place a to place b 
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//sources: youtube, geeksforgeeks, lecetureslides
 
int infinity = 100000;
 
int extractMin(int shortestPathsHolder[], bool visited[],int n){
	int minimum= infinity;
    vector <int> hold;
    int min=0;
 
	for (int i = 0; i < n; i++)
		if (visited[i] != true &&shortestPathsHolder[i] <= minimum){
			minimum = shortestPathsHolder[i]; 
            hold.push_back(i); 
        }
        min = hold.back();
	return min;
}
 
 
int main(){
	int u,v,w,n,m,start,end;
	cin >>n >> m;
	cin >> start >> end;
	int graph[n][n];
    int shortestPathsHolder[n]; // hold the shorted cost from source to other index
    bool visited[n]; // visited or nah?
	
	//cout <<"INITIALIZING ZEROS" << endl;
	for (int i = 0; i < n; i++){
	    for (int j = 0; j < n; j++){
	        graph[i][j] = 0;
	    }
	}
	//filling in the adjacency matrix
	for (int i = 0; i < m; ++i) {
        cin >> u>> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
	}
    //cout << "Print 2D array" << endl; //checking how matrix looks
   	// for (int i = 0; i < V; i++){
	//     for (int j = 0; j < V; j++){
	//         cout << graph[i][j] << " ";
	//     }
    //     cout << endl;
	// }
	
    //everything infinity and false since they are not visite yet
    for (int i = 0; i < n; i++){
       shortestPathsHolder[i] = infinity;
        visited[i] = false;
    }
    // source starts with 0
    shortestPathsHolder[start] = 0;
 
    // shortest path for all vertex
    for (int i = 0; i < n - 1; i++) {
 
       int u = extractMin(shortestPathsHolder,visited,n);
        //cout << "u: " << u << endl;
 
       visited[u] = true;
 
        for (int j = 0; j < n; j++){
            int weight = graph[u][j];
            if ((!visited[j] && weight) && (shortestPathsHolder[u] != infinity)
                && (shortestPathsHolder[u] + weight < shortestPathsHolder[j]))
                shortestPathsHolder[j] = shortestPathsHolder[u] + weight;
        }
    }
    
    //cout << "Final Answer:"
    cout << shortestPathsHolder[end];
    
}