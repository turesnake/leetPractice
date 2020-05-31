/*
 * ====================== leet_965.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 965. 单值二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_965 {//~


bool isUnivalTree( TreeNode* root ) {

    std::deque<TreeNode*> que {root};
    int fstVal = root->val;
    while( !que.empty() ){
        TreeNode *tp = que.front();
        que.pop_front();
        if( tp->val!=fstVal ){ return false; }
        if(tp->left){ que.push_back(tp->left); }
        if(tp->right){ que.push_back(tp->right); }
    }
    return true;
}





//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: 965 :end ~~~~\n" );
}
}//~
