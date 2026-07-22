class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>adjlist(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto prerequisite:prerequisites)
        {
            adjlist[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int>ans;//This is topological sort.
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();

            ans.push_back(temp);
            for(auto ngb:adjlist[temp])
            {
                indegree[ngb]--;
                if(indegree[ngb] == 0)
                {
                    q.push(ngb);
                }
            }
        }
        return ans.size() == numCourses;
    }
};