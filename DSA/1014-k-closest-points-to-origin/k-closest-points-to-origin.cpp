class Solution {
public:
    class compare{
        public:
        bool operator()(vector<int>a,vector<int>b)
        {
            int dist_a = a[0] * a[0] + a[1] * a[1];
            int dist_b = b[0] * b[0] + b[1] * b[1];

            return dist_a < dist_b;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>>ans;
        priority_queue<vector<int>,vector<vector<int>>,compare>pq;
        for(auto point : points)
        {
            pq.push(point);

            if(pq.size()>k)
                pq.pop();
        }

        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;    
    }
};