/******************************************************************************


*******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <bits/stdc++.h>
#include "Graph.h"
#include <string> 
#include <algorithm>
using namespace std;

Graph::Graph(int b)
{
    this->V = b;
    adj_matrix.resize(b, vector<int>(b));
    for (int i = 0; i < adj_matrix.size(); i++)
    {
        for (int j = 0; j < adj_matrix[i].size(); j++)
        {
            adj_matrix[i][j]=0;
        }    
        
    }
    graph.resize(b+1);
    
}
 
void Graph::addEdge(int u, int v)
{
    graph[u].push_back(v);
    adj_matrix[u][v]=1;
}

string Graph::BFS(int source, int target) {
    
    int dist[V+ 5];
    int parent[V + 5];
    bool visited[V + 5];
    queue<int> q;
    q.push(source);
    visited[source] = true;
    dist[source] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto adjacent : graph[u]) {
            
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                dist[adjacent] = dist[u] + 1;
                parent[adjacent] = u; // record parent of v as u
                q.push(adjacent);
            }
        }
        if (u == target) {
            break;
        }
    }
    string h="";
    h=h+to_string(dist[target])+" ";
    vector<int> path;
    int curr = target;
    while (curr != source) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(source);
    for (int i = path.size() - 1; i > 0; i--) {
        h=h+to_string(path[i])+"->";
    }
    h=h+to_string(path[0]);
    return h;
}

string Graph::find_cycle(int source) {
    visited[source] = true;
    parent[source] = -1;
    d=d+to_string(source)+"->";
    for (auto i : graph[source]) {
        if (!visited[i]) {
            if (dfs(i, source,source)) {
                str_dfs=to_string(count+1)+" "+d+to_string(source);
                return str_dfs;
            }
            else{
                str_dfs="-1";
                return str_dfs;
                
            }
        }    
        
    }
    return str_dfs;
}

bool Graph::dfs(int node, int source,int p) {
    visited[node] = true;
    parent[node] = p;
    d=d+to_string(node)+"->";
    count++;
    if(count>1&&adj_matrix[node][source]==1){
                return true;
                exit(0);
    }
    
    for (auto i : graph[node]) {
        if (!visited[i]) {
            if (dfs(i, source,node)) {
                return true;
                
            }
        } 
        else {
            if (!finished[i]&& parent[i] == source) {
                return true;
            }
        }

    }

    finished[node] = true;
    d.erase(d.size() - 1);
    d.erase(d.size() - 1);
    count--;
    return false;
}

void Graph::print_vector_list(vector<list<int>> gr){
    list<int>::iterator it;
    for (auto adjacent : gr) {
        adjacent.sort();
        for (it=adjacent.begin(); it!=adjacent.end(); ++it){
            cout << ' ' << *it;
            
        }
        cout << endl;
    }
}

void Graph::print_adjMatrix(){
    int n=adj_matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }    
    
}





