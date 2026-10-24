class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &v : prerequisites){
            int a = v[0];
            int b = v[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> order;

        while(!q.empty()){

            int u = q.front();
            q.pop();
            order.push_back(u);

            for(int &v: adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(order.size() == numCourses){
            return order;
        }

        return {};
    }
};