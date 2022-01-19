#include<iostream>
#include<bits/stdc++.h>
#define INF INT_MAX
#define LOW INT_MIN

using namespace std;

int nextMinimum(vector<int>& weights, vector<bool>& taken){
    int min = INT_MAX, min_index;
    for(int i=0; i<weights.size(); i++){
        if(!taken[i] && min < weights[i]){
            min_index = i;
            min = weights[i];
        }
    }
    return min_index;
}

void printMST(vector<int>& parent, vector<vector<int>>& graph){
    cout<<"printing the mst\n";
    int n = graph.size();
    for(int i=1; i<n; i++){
        cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]];
    }
}

void prims_algo(int n, vector<vector<int>>& graph){
    vector<bool> mstset(n, false);
    vector<int> parent(n, -1);
    int count = 0;
    vector<int> weight(n, INF);
    weight[0] = 0;
    parent[0] = -1;
    for(; count < n-1; count++){
        int v = nextMinimum(weight, mstset);
        mstset[v] = true;
        for(int i=0; i<n; i++){
            if(mstset[i] == false && graph[v][i] < weight[v]){
                parent[i] = v;
                weight[i] = graph[v][i];
            }
        }
    }
    printMST(parent, graph);
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    int e;
    for(int i=0; i<e; i++){
        int s, f, w;
        cin>>s>>f>>w;
        graph[s][f] = w;
    }
    return 0;
}