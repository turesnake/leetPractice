/*
 * ====================== leet_1325.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1325. 删除给定值的叶子节点
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1325 {//~


// 后续遍历 37%, 100%
class S{

    int targetVal {};

    // tp not null
    // ret: false: null leaf
    bool work( TreeNode *tp ){
        bool l = (tp->left) ? work(tp->left) : false;
        bool r = (tp->right) ? work(tp->right) : false;
        if( !l && tp->left ){ tp->left = nullptr; }
        if( !r && tp->right ){ tp->right = nullptr; }
        if( !l && !r && tp->val==targetVal ){
            return false;
        }
        return true;
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root){ return nullptr; }
        targetVal = target;
        bool ret = work(root);
        return ret ? root : nullptr;
    }
};




//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: 1325 :end ~~~~\n" );
}
}//~
