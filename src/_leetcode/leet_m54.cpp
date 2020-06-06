/*
 * ====================== leet_m54.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题54. 二叉搜索树的第k大节点
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m54 {//~


// 倒置的中序遍历
class S{
public:
    // 迭代版 15% 100%
    // 树非空
    int kthLargest( TreeNode* root, int k ){

        int idx = 1;
        std::stack<TreeNode*> stk {};
        TreeNode *ptr = root; 
        while( ptr || !stk.empty() ){
            if(ptr){
                stk.push(ptr);
                ptr = ptr->right;
            }else{
                ptr = stk.top();
                stk.pop();
                //
                if( idx == k ){
                    return ptr->val;
                }
                idx++;
                ptr = ptr->left;
            }
        }
        return -99;//never reach
    }
};




//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: m54 :end ~~~~\n" );
}
}//~
