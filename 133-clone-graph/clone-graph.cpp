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
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {

        if(!node) return NULL;
        if(mp.find(node)!= mp.end()) return mp[node];


        Node* head = new Node(node->val);
        int n = node->neighbors.size();
        vector<Node*> nums;
        mp[node] = head;
        
        for(int i = 0 ; i<n ; i++ ){
             
                Node* temp = cloneGraph(node->neighbors[i]);
                nums.push_back(temp);
            
        }
        head->neighbors = nums;
        
        return head;
    }
};