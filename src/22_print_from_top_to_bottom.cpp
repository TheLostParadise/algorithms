/*
 * 题目描述：
 *     从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 * 
 * struct TreeNode {
 * 	int val;
 * 	struct TreeNode *left;
 * 	struct TreeNode *right;
 * 	TreeNode(int x) :
 * 			val(x), left(NULL), right(NULL) {
 * 	}
 * };
 * 
 * 解题思路：
 *     从上到下，从左到右打印，由于树结构在访问左子节点时没有指向右子节点
 *     的指针，所以需要额外的空间存储指针，这里使用deque双端队列来完成
 *     进入循环之前先压入根节点，然后访问根节点时把左右子节点压入
 *     从尾部添加，从头部取值，即先进先出
 * 
 */
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> vals;
        if (root == NULL)
            return vals;
            
        deque<TreeNode *> nodes;        
        nodes.push_back(root);
        while (nodes.size() > 0) {
            TreeNode *node = nodes.front();
            nodes.pop_front();
            vals.push_back(node->val);
            if (node->left)
                nodes.push_back(node->left);
            if (node->right)
                nodes.push_back(node->right);
        }
        
        return vals;
    }
};