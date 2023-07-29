#include<bits/stdc++.h>
using namespace std;

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


class Solution {
public:

    void make(Node* node, Node* head, unordered_map<Node*,Node*> &vis)
    {
        vis[node]=head;
        for(auto &i:node->neighbors)
        {
            if(vis.find(i)==vis.end())
            {
                Node* temp = new Node(i->val);
                head->neighbors.push_back(temp);
                make(i,temp,vis);
            }
            else
                head->neighbors.push_back(vis[i]);
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        unordered_map<Node*,Node*> vis;
        Node* head = new Node(node->val);
        make(node,head,vis);
        return head;
    }
};