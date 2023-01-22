#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
typedef pair<int, int> Pairs;
int A[1000000];
class Graph{   
    public:
    int V, E;
    vector< pair<int, Pairs> > edges;
   
    //contructor
    Graph(int V, int E){
        this->V = V;
        this->E = E;
    }
    //destructor
    ~Graph(){}
    
    void addEdge(int e){   
        int u,v,w;
        for (int i = 0; i < e; i++){
            cin >> u >> v >> w;
            edges.push_back({w, {u, v}});
        }
    }
    
    //union
    void unioon(int u, int v){ // to check if the two vertices are in th same union or not
    int a = find_set(u);
    int b = find_set(v);
    A[a] = A[b];
    }
    
    //find the parent of the given node.
    int find_set(int u){
    while(A[u] != u){
        A[u] = A[A[u]];
        u = A[u];
    }
    return u;
    }
    
    //KRUSKAL's ALGORITHM
    void kruskalAlgoMST(int t){
    int need = t -1;
    vector <int> weights;
     //cout << "Sorting array" << endl;
    sort(edges.begin(), edges.end()); // sorting the edges
     
    
    for (int i = 0; i< edges.size(); i++){
        int u = edges.at(i).second.first;
        int v = edges.at(i).second.second;
        int w = edges.at(i).first;
       
        if(find_set(u) != find_set(v)) //making sure it doesnt make a cycle
        {
            weights.push_back(w);
            unioon(u, v);
        }    
    }
        cout << weights.back();
    }
    
    void initialize(){ // to initialize set A array to all zero
    for(int i = 0;i < 1000;++i)
        A[i] = i;
    }
    
    void printfindset(){
        for (int i =0; i < 100; i++){
            cout << A[i] << " " ;
        }
    }
 
};
 
int main()
{
    int v, e;
    cin >> v >> e;
    Graph g(v, e);
  
    g.initialize(); 
    g.addEdge(e);
    g.kruskalAlgoMST(v);
    //g.printfindset();
    //cout << "ENNDD" << endl;
    return 0;
}
 