/*
 * ====================== leet_m32_1.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题32 - I. 从上到下打印二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m32_1 {//~



std::vector<int> levelOrder( TreeNode* root ){

    if( !root ){ return {}; }
    std::deque<TreeNode*> que { root };
    std::vector<int> elems {};
    while( !que.empty() ){
        TreeNode *tp = que.front();
        que.pop_front();
        elems.push_back( tp->val );
        if( tp->left  ){ que.push_back(tp->left); }
        if( tp->right ){ que.push_back(tp->right); }
    }
    return elems; 
}




//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: m32_1 :end ~~~~\n" );
}
}//~
