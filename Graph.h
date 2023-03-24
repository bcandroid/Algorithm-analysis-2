/******************************************************************************


*******************************************************************************/
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
struct Node {
    public:
        int x, y, p;
        
};
class Graph{ 
    private:
        int V;
    public:
        
        Graph(int);
        vector<int>vec;
        bool visited[1000], finished[1000];
        int parent[1000];
        vector<list<int>>graph;
        vector<vector<int>> adj_matrix; 
        string str_dfs="";
        string d="";
        int count=0;
        bool dfs(int, int,int);
        void addEdge(int,int);
        string BFS(int,int);
        string find_cycle(int );
        void print_adjMatrix();
        void print_vector_list(vector<list<int>>);
         

};