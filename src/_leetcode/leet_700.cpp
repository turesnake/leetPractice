/*
 * ====================== leet_700.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 700. 二叉搜索树中的搜索
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_700 {//~

// bfs 43%, 6%
TreeNode* searchBST(TreeNode* root, int val) {

    if( !root ){ return nullptr; }
    std::deque<TreeNode*> que {root};
    while( !que.empty() ){
        TreeNode *tp = que.front();
        que.pop_front();
        if( tp->val==val ){ return tp; }
        if(tp->left){que.push_back(tp->left);}
        if(tp->right){que.push_back(tp->right);}
    }
    return nullptr;
    
}





//=========================================================//
void main_(){

    debug::log( "\n~~~~ leet: 700 :end ~~~~\n" );
}
}//~
