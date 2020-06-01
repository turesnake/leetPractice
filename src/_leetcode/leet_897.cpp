/*
 * ====================== leet_897.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 897. 递增顺序查找树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_897 {//~


// 71%, 100%
class S{
public:

    // root 非空
    TreeNode* increasingBST(TreeNode* root) {

        TreeNode *out = new TreeNode(0);//sentry
        TreeNode *po = out;
        std::stack<TreeNode*> stk {};
        TreeNode *ptr = root;
        while( ptr || !stk.empty() ){
            if(ptr){
                stk.push(ptr);
                ptr=ptr->left;
            }else{
                ptr=stk.top();
                stk.pop();
                //---//
                ptr->left = nullptr;// 断开
                po->right = ptr;
                po=po->right;
                //---//
                ptr=ptr->right;
            }
        }
        return out->right;
    }

};




//=========================================================//
void main_(){


    

    debug::log( "\n~~~~ leet: 897 :end ~~~~\n" );
}
}//~
