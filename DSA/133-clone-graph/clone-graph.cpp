/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>umap;

    void DFS(Node* node, Node* clone_node)
    {
        for(Node* ngb:node->neighbors)
        {
            if(umap.find(ngb) == umap.end())
            {
                Node* clone = new Node(ngb->val);
                umap[ngb] = clone;
                clone_node->neighbors.push_back(clone);

                DFS(ngb,clone);
            }
            else
            {
                clone_node->neighbors.push_back(umap[ngb]);
            }
        }
    }
    Node* cloneGraph(Node* node) 
    {
        if(!node)
            return nullptr;
        
        Node* clone_node = new Node(node->val);
        umap[node] = clone_node;
        DFS(node,clone_node);

        return clone_node;
        
    }
};