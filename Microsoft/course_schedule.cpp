#include <bits/stdc++.h>
using namespace std;

//using bfs/topological sort
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it: prerequisites)
            adj[it[1]].push_back(it[0]);

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i<numCourses; i++){
            for(auto it: adj[i])
                indegree[it]++;
        }

        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] ==0)
                    q.push(it);
            }
        }

        if(ans.size() == numCourses)
            return true;
        else    return false;
    }
};


//using dfs(cycle detection)
class Solution {
public:
    bool cycleDetect(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto nbg : adj[node]){
            if(!visited[nbg]){
                bool cycleFound = cycleDetect(nbg, visited, dfsVisited, adj);
                if(cycleFound)
                    return true;
            }
            else if(dfsVisited[nbg])
                return true;
        }

        dfsVisited[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        for(int i = 0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        unordered_map<int, bool> visited, dfsVisited;
        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
                bool cycleFound = cycleDetect(i, visited, dfsVisited, adj);
                if(cycleFound)
                    return false;
            }
        }

        return true;
    }
};