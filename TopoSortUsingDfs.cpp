#include<bits/stdc++.h>
#define ll long long 
#define nl "\n"
using namespace std ;

// This is possible if graph is  Directed Acyclic graph (DAG) 

void topoSortUsingDfs(vector<vector<ll>>&graph ,  vector<ll>&visited , vector<ll>&order , ll root){
       
       if(visited[root])return  ; // If that node is visited then no need to do something ..
       
       visited[root] = 1 ;        // Else mark that node as visited ....
       
       for(ll &child : graph[root]){
         if(!visited[child]){
            topoSortUsingDfs(graph ,visited , order , child) ;   // Dfs call for child node ...
         }
       }
       
       order.push_back(root) ;     // When all the children are visited then push that node into the stack ..
   
    return ;
}

int main() {
    ll node , edge ; cin >> node >> edge ;
    
    vector<vector<ll>>graph(node + 1 , vector<ll>() ) ;
    
    for(ll i = 1 ; i <= edge ; i ++){     // Taking inputs graph 
      ll u , v ; cin >> u >> v ;
      graph[u].push_back(v) ;
    }
    
    vector<ll>visited(node + 1 , 0 ) ; vector<ll>order ;  // You can also use stack instead of vector both are runs fine 
    for(ll i = 1 ; i <= node ; i ++){                 //  calling dfs for all nodes 
        if(!visited[i]){
          topoSortUsingDfs(graph , visited , order , i ) ;
        }
    }
    
  reverse(order.begin() , order.end()) ;
  
  for(int i = 0 ; i < node ; i ++){
    cout << order[i] << " " ;        // printing elements in topological ordering...
  }
   cout << nl ;
    
    return 0 ;
}
