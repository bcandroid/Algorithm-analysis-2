/******************************************************************************

*******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <bits/stdc++.h>
#include "Graph.h"
#include <fstream>
using namespace std;

int distance(Node a, Node b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}
void file_adj(vector<vector<int>>);
void file_bfs(string );
void file_dfs(string );

int main(int argc, char* argv[])
{
    vector<vector<int>>matrix;
    int source;
    int target;
    int n;
    ifstream file(argv[1]);
    // Read the file line by line
    string line;
    file>>n>>source>>target ;
    for(int i = 0; i< n; ++i){
        int k,l,m;
        vector<int>row;
        file>>k>>l>>m;
        row.insert(row.begin(),k);
        row.insert(row.begin()+1,l);
        row.insert(row.begin()+2,m);
        matrix.push_back(row);
        
    }    
    file.close();
    Graph g(n);
    vector<Node>not_real=vector<Node>(n);
    for (int i = 0; i < n; i++) {
        not_real[i].x=matrix[i][0];
        not_real[i].y=matrix[i][1];
        not_real[i].p=matrix[i][2];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j){
                continue;
            }
            
            if (distance(not_real[i],not_real[j]) <= not_real[i].p && distance(not_real[i],not_real[j]) <= not_real[j].p){
                        g.addEdge(i, j);
            }
            
        }
    }
    
    file_adj(g.adj_matrix);
    string str=g.BFS(source,target);
    file_bfs(str);
    string df=g.find_cycle(source);
    file_dfs(df);
    return 0;
}
void file_adj(vector<vector<int>>mat){
    ofstream adj("graph.txt");
    if(adj.is_open()){
        for(auto vec:mat){
            for(auto elem:vec){
                adj<<elem<<" ";
            }
            adj<<endl;
        }
        adj.close();
    }
    
    return;
}
void file_bfs(string s){
    ofstream jbfs("bfs.txt");
    if(jbfs.is_open()){
        jbfs<<s;
        
    }
    return;
}
void file_dfs(string s){
    ofstream jdfs("dfs.txt");
    if(jdfs.is_open()){
        jdfs<<s;
        
    }
    return;
}
    
    
    
    
