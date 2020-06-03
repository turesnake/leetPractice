/*
 * ====================== leet_156.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 156. 上下翻转二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_156 {//~



// 42%， 100%
class S{
public:
    TreeNode* upsideDownBinaryTree( TreeNode* root ){

        if(!root || !root->left ){ return root; }
        // 树至少有2个 left 节点

        TreeNode *ptr = root;
        std::stack<TreeNode*> stk {};
        while( ptr ){
            stk.push(ptr);
            ptr = ptr->left;
        }
        // 整条右节点，全部存储在 stk 中
        ptr = stk.top(); // most left leaf
        stk.pop(); // stk.top() = ptr's parent

        TreeNode *sentry = new TreeNode(0);
        TreeNode *sp = sentry;

        while( !stk.empty() ){

            if( stk.top()->right ){ ptr->left = stk.top()->right; }

            sp->right = ptr;
            sp = sp->right;// sp 爬到 ptr 位置上去
            ptr = stk.top();
            ptr->left = nullptr;
            ptr->right = nullptr;
            stk.pop();
        }
        sp->right = ptr;// 补上原树的 root
        return sentry->right;
    }
};



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 156 :end ~~~~\n" );
}
}//~
