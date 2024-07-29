class Solution {
public:
    deque<char> t={'|'};
    void f(TreeNode* node, deque<char>& s)
    {
        if (!node) return;
        s.push_front(node->val+'a');
        if (!node->left && !node->right)
        {
            if (s<t) t=s; 
        }
        f(node->left, s);
        f(node->right, s);
        s.pop_front(); 
    }

    string smallestFromLeaf(TreeNode* root) 
    {
        deque<char> s={};
        f(root, s);
        return string(t.begin(), t.end());
    }
};