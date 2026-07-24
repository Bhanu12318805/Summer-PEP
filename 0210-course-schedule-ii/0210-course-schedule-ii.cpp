class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto &p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        vector<int> indeg(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            for(auto neigh : graph[i]){
                indeg[neigh]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i] ==0){
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(auto neigh : graph[node]){
                indeg[neigh]--;
                if(indeg[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        if(order.size() != numCourses){
            return {};
        }
        return order;
    }
};