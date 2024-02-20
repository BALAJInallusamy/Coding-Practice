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
    void rec(Node* node, unordered_map<int,vector<int>>& graph){
        if(node != nullptr && graph.find(node->val) == graph.end()){
            graph[node->val]={};
            for(auto it:node->neighbors){
                graph[node->val].push_back(it->val);
                rec(it,graph);
            }   
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<int,vector<int>> graph;
        unordered_map<int,Node*> nodes;
        rec(node,graph);
        for(auto it:graph){
            nodes[it.first]=new Node(it.first);
        }
        for(auto it:graph){
            vector<Node*> adj={};
            for(auto x:it.second){
                adj.push_back(nodes[x]);
            }
            nodes[it.first]->neighbors=adj;
        }
        return nodes[1];
    }
};