#include<bits/stdc++.h>
#define IO \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define CP \
    ios::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

struct node{
    int key;
    node *next;
    node(int key){
        this->key = key;
        next = NULL;
    }
};

struct Graph{
    int n;
    node **adjList;
    Graph(int n){
        this->n = n;
        adjList = new node*[n];
        for(int i=0; i<n; i++) adjList[i] = NULL;
    }
};

void printGraph(string message, Graph *graph){
    cout << message;
    for(int i=0; i<graph->n; i++){
        cout << i << ": ";
        node *temp = graph->adjList[i];
        while(temp){
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    cout << "\n";
}

void insert(Graph *graph, pair<int,int> p){
    if(max(p.first, p.second) >= graph->n) return;
    node *newNode = new node(p.second);
    if(graph->adjList[p.first]){
        node *temp = graph->adjList[p.first];
        if(temp->key > p.second){
            newNode->next = temp;
            graph->adjList[p.first] = newNode;
        }
        else{
            while(temp->next != NULL && temp->next->key < p.second) temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    } else graph->adjList[p.first] = newNode;
}

Graph *takeGraphInput(){
    int n; cin >> n; 
    Graph *graph = new Graph(n);
    for(int i=0; i<n; i++){
        int u, v; cin >> u >> v;
        insert(graph, {u,v});
        insert(graph, {v,u});
    }
    return graph;
}

int main(){
    IO; 
    Graph *graph1 = takeGraphInput();
    printGraph("Graph 1:\n", graph1);
    Graph *graph2 = takeGraphInput();
    printGraph("Graph 2:\n", graph2);
    Graph *graph3 = takeGraphInput();
    printGraph("Graph 3:\n", graph3);
    return 0;
}