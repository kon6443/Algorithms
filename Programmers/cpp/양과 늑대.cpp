#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int answer = 0;

void print2DVector(vector<vector<int>> &graph) {
    for(int i=0;i<graph.size();i++) {
        cout<<i<<": [";
        for(int j=0;j<graph[i].size();j++) {
            cout<<graph[i][j]<<" ";
        }cout<<"]"<<endl;
    }
}

void understandEasier(int current_position, vector<int> &approachableAnimals) {
    cout<<"current: "<<current_position<<endl;
    cout<<"next: ";
    for(const auto &item: approachableAnimals) cout<<item<<" ";
    cout<<endl;
}

void dfs(vector<vector<int>> &graph, vector<int> &info, int current_position, int wolf, int sheep, vector<int> approachableAnimals) {
    // understandEasier(current_position, approachableAnimals);
    
    (info[current_position]) ? (wolf++) : (sheep++);
    answer = max(answer, sheep);
    if(wolf>=sheep) return;
    
    // next vector represents that every approachable animals except itself.
    for(int animal=0;animal<approachableAnimals.size();animal++) {
        vector<int> next = approachableAnimals;
        next.erase(next.begin()+animal);
        
        // adding child animals to next vector 
        for(int j=0;j<graph[approachableAnimals[animal]].size();j++) 
            next.push_back(graph[approachableAnimals[animal]][j]);
        
        // Call dfs() from current animal with every approachable animals.
        dfs(graph, info, approachableAnimals[animal], wolf, sheep, next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    // making a graph that represents connected animals from one to others.
    vector<vector<int>> graph(info.size());
    for(int i=0;i<edges.size();i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    // approachableAnimals represents animals that can be approached.
    vector<int> approachableAnimals;
    for(int i=0;i<graph[0].size();i++) approachableAnimals.push_back(graph[0][i]);
    dfs(graph, info, 0, 0, 0, approachableAnimals);
    return answer;
}

