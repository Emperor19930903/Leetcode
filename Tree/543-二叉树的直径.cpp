// 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

// 示例 :
// 给定二叉树

//           1
//          / \
//         2   3
//        / \     
//       4   5    
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
// 注意：两结点之间的路径长度是以它们之间边的数目表示。

class Solution {
public:
    int res0=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        res0=max((maxDepth(root->left)+maxDepth(root->right)),res0);
        return res0;
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int leftMax=maxDepth(root->left);
        int rightMax=maxDepth(root->right);
        int res=max(leftMax,rightMax)+1;
        return res;
    }
};
时间复杂度：O（N^2）

优化：我们应该把计算「直径」的逻辑放在后序位置，准确说应该是放在 maxDepth 的后序位置，因为 maxDepth 的后序位置是知道左右子树的最大深度的。

class Solution {
public:
    int res0=0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return res0;
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int leftMax=maxDepth(root->left);
        int rightMax=maxDepth(root->right);
        int res=max(leftMax,rightMax)+1;
        int mydiameter=leftMax+rightMax;
        res0=max(mydiameter,res0);
        return res;
    }
};
时间复杂度：O（N）
