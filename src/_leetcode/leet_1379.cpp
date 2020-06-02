/*
 * ====================== leet_1379.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1379. 找出克隆二叉树中的相同节点
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1379 {//~


// 先序遍历  35%， 100%
// 两树同时遍历，左树找到时，右树的同步指针，就是我们需要的
class S{
public:
    // 树一定有节点 target 一定在 原树中
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        std::stack<TreeNode*> stk1 {};
        std::stack<TreeNode*> stk2 {};
        stk1.push(original);
        stk2.push(cloned);

        while( !stk1.empty() ){
            TreeNode *tp1 = stk1.top();
            TreeNode *tp2 = stk2.top();
            stk1.pop();
            stk2.pop();
            if( tp1 == target ){ return tp2; } // find
            if(tp1->left){
                stk1.push(tp1->left);
                stk2.push(tp2->left);
            }
            if(tp1->right){
                stk1.push(tp1->right);
                stk2.push(tp2->right);
            }
        }
        return nullptr;//never reach
    }
};





//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: 1379 :end ~~~~\n" );
}
}//~
