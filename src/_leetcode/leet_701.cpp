/*
 * ====================== leet_701.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.03
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 701. 二叉搜索树中的插入操作
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_701 {//~


// 这题好像有 3 种解法


// 68%， 20%
class S{
    int target {};
    // tp not null
    void work( TreeNode *tp ){
        if( target < tp->val ){
            if(tp->left){
                work(tp->left);
            }else{
                tp->left = new TreeNode(target);
            }
        }else{
            if( tp->right ){
                work(tp->right);
            }else{
                tp->right = new TreeNode(target);
            }
        }
    }

public:
    // 目标值，一定不再 bst 中
    TreeNode* insertIntoBST( TreeNode* root, int val ){

        if(!root){ return new TreeNode(val); }
        target = val;
        work(root);
        return root;
    }
};



//=========================================================//
void main_(){
    
    debug::log( "\n~~~~ leet: 701 :end ~~~~\n" );
}
}//~
