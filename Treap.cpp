#include<iostream>
#include<vector>
using namespace std;
struct sort_cmp {
    bool operator()(const vector<int>& left, const vector<int>& right) {
        if(left[1]>right[1]) return true;
        return false;
    }
};
struct TreeNode {
    pair<int,int> val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(pair<int,int> x) : val(x), left(NULL), right(NULL) {}
};

void printTree(TreeNode* root) {
    if(root == NULL) return;
    cout<<root->val.first<<","<<root->val.second<<endl;
    printTree(root->left);
    printTree(root->right);
}

TreeNode* createBST(TreeNode* root, vector<int> x) {
    if(root == NULL) {
        root = new TreeNode(make_pair(x[0],x[1]));
        return root;
    }
    if(x[0] < root->val.first) 
        root->left = createBST(root->left,x);
    else
        root->right = createBST(root->right, x);
    return root;
}

TreeNode* solution(vector<vector<int> > v) {
    //sort for heap formation
    sort(v.begin(),v.end(),sort_cmp());
    TreeNode* root = NULL;
    if(v.size() == 0) return root;
    for(auto x:v) {
        root = createBST(root,x);
    }
    printTree(root);
    return root;
}

int main(){
    vector<vector<int> > v;
    vector<int> t;
    // [(1, 4), (8, 5), (3, 6), (10, -1), (4, 7)]
    t.push_back(1);
    t.push_back(4);
    v.push_back(t); t.clear();
    t.push_back(8);
    t.push_back(5);
    v.push_back(t); t.clear();
    t.push_back(3);
    t.push_back(6);
    v.push_back(t); t.clear();
    t.push_back(10);
    t.push_back(-1);
    v.push_back(t); t.clear();
    t.push_back(4);
    t.push_back(7);
    v.push_back(t); t.clear();

     vector<vector<int> > v1;
    vector<int> t1;
    // [(1, 6), (3, 7), (2, 4)]
    t1.push_back(1);
    t1.push_back(6);
    v1.push_back(t1); t1.clear();
    t1.push_back(3);
    t1.push_back(7);
    v1.push_back(t1); t1.clear();
    t1.push_back(2);
    t1.push_back(4);
    v1.push_back(t1); t1.clear();
    
    solution(v);
    cout<<endl<<endl;
    solution(v1);

    return 0;
}

