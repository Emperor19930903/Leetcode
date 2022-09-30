//C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res=1;   //不是说非要unsigned long long 理论上ull的最大值也不够。关键是这里借助无符号整型在溢出的时候自动根据32位，或者64位取模。本题换成unsigned int一样能过
        vector<pair<TreeNode*,unsigned long long >>vec;
        vec.emplace_back(root,1);
        while(!vec.empty())
        {
            vector<pair<TreeNode*,unsigned long long>>tmp;
            for(auto& [node,index] :vec)
            {
                if(node->left)
                    tmp.emplace_back(node->left,index*2);
                if(node->right)
                    tmp.emplace_back(node->right,index*2+1);
                
            }
            res=max(res,vec.back().second-vec[0].second+1);
            vec=move(tmp);    // move：将tmp的变量传给vec
            
        }
        return res;
    }
};

//python
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        res = 1
        arr = [[root, 1]]
        while arr:
            tmp = []
            for node, index in arr:
                if node.left:
                    tmp.append([node.left, index * 2])
                if node.right:
                    tmp.append([node.right, index * 2 + 1])
            res = max(res, arr[-1][1] - arr[0][1] + 1)
            arr = tmp
        return res
