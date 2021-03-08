// 1. make graph
// 2. if cycle exists -> cannot satisfy given prerequisites

enum State{INIT, VISITING, VISITED};

class Solution {
public:
    
    bool hasCycle(vector<vector<int>>& graph,int node,vector<State>& state){
        if(state[node] == VISITED)  return false;
        if(state[node] == VISITING) return true;
        
        state[node] = VISITING;
        for(int i: graph[node]){
            if(hasCycle(graph,i,state)) return true;
        }
        state[node] = VISITED;
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<State> state(numCourses);
        for(auto &p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(hasCycle(graph,i,state)) return false;
        }
        return true;
    }
};
