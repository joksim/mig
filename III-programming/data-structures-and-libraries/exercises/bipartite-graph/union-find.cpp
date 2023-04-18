#include <iostream>
#include <vector>
#include <utility> // For std::pair

using std::vector;
using std::pair;


int find(vector<pair<int,int>> &parent, int k){
    if(parent[k].first == -1 || parent[k].first==k){
        parent[k].first = k;
        return k;
    }
    parent[k].first=find(parent,parent[k].first);
    return parent[k].first;
}

void unionFind(vector<pair<int,int>> &parent, int x, int y){
   int a = find(parent,x);
    int b = find(parent,y);
    if(a != b){
       if(parent[a].second < parent[b].second){
		   parent[a].first=b;
	   }else if(parent[a].second > parent[b].second){
			parent[b].first=a;
		}else{
			parent[b].first=a;
			parent[a].second += 1;
		}
    }
}
bool isBipartite(vector<vector<int>>& graph) {
    int n =graph.size();
    vector<pair<int,int>> parent(n,{-1,0});
    for(int i=0;i<n;i++){
        for(int j=0;j<graph[i].size();j++){
		 // node and neighbour shouldn't belong to same set in bipartite
            if(find(parent,i) == find(parent,graph[i][j])){
                return false;
            }
			// all node neighbours should belong to one set
            unionFind(parent,graph[i][j],graph[i][0]);
        }
    }
    return true;
}
