/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int max = 0;
    int maxDepth(Node* root) {
        if(root == NULL) return max;
        solution(root,1);
        return max;
    }
    void solution(Node* node, int depth)
    {
        for(int i = 0; i<node->children.size(); i++)
        {
            solution(node->children[i], depth+1);
        }
        if(max < depth) max = depth;
        return;
    }
};