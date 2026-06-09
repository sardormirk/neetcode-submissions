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
    Node* cloneGraph(Node* node) {

        if (!node) return nullptr;
        unordered_map<Node*, Node*> cloned;
        queue<Node*> q;

        cloned[node] = new Node(node->val);
        q.push(node);

        while (!q.empty())
        {
            Node* cur = q.front(); q.pop();
            
            for (Node* node : cur->neighbors)
            {
                if (!cloned.contains(node))
                {
                    cloned[node] = new Node(node->val);
                    q.push(node);
                }
                cloned[cur]->neighbors.push_back(cloned[node]);
            }
        }

        return cloned[node];
    }
};
