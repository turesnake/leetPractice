/*
 * ====================== leet_671.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 671. 二叉树中第二小的节点
 */
#include "innLeet.h"
#include "TreeNode1.h"




namespace leet_671 {//~


int findSecondMinimumValue( TreeNode* root ){

    if( !root ){ return -1; }
    std::deque<TreeNode*> que { root };
    int head = root->val;
    int mmin = INT_MAX; // 比头部元素大的值中，最小的
    bool isFind = false;
    while( !que.empty() ){
        TreeNode *tp = que.front();
        que.pop_front();
        if( tp->val > head ){
            if( !isFind ){ isFind = true; }
            mmin = std::min( mmin, tp->val );
            continue;//不再访问它的儿子
        }
        if( tp->left ){ que.push_back(tp->left); }
        if( tp->right ){ que.push_back(tp->right); }
    }
    return isFind ? mmin : -1;
}



//=========================================================//
void main_(){

    
    
    

    debug::log( "\n~~~~ leet: 671 :end ~~~~\n" );
}
}//~
