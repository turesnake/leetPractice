/*
 * ====================== leet_1214.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1214. 查找两棵二叉搜索树之和
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1214 {//~


// 朴素法 54%, 100%
// 中序遍历 root1 每个元素，检查其对应值b，是否在 root2 中
class S{

    TreeNode *tree2 {};

    bool is_find_in_tree2( int target ){
        TreeNode *p = tree2;
        while( p ){
            int v = p->val;
            if( target < v ){
                p = p->left;
            }else if( target > v ){
                p = p->right;
            }else{//==
                return true;
            }
        }
        return false;
    }

public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {

        if( !root1 || !root2 ){ return false; }

        tree2 = root2;
        TreeNode *ptr = root1;
        std::stack<TreeNode*> stk {};
        while( ptr || !stk.empty() ){
            if(ptr){
                stk.push(ptr);
                ptr = ptr->left;
            }else{
                ptr = stk.top();
                stk.pop();
                // check
                bool ret = is_find_in_tree2(target-ptr->val);
                if(ret){ return true; }
                ptr = ptr->right;
            }
        }
        return false;
    }


};



//=========================================================//
void main_(){


    

    debug::log( "\n~~~~ leet: 1214 :end ~~~~\n" );
}
}//~
