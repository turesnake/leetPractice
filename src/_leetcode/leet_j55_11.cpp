/*
 * ====================== leet_j55_11.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.22
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 55 - II. 平衡二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"



namespace leet_j55_11 {//~


// 最简单的 递归 实现   29%  100%
class S{

    bool isFindErr {false};

    // tp 一定非空
    // ret: 负数表示 在子树中 发现 非平衡结构，正数表示 
    int work( TreeNode* tp ){

        int ldeep = tp->left ? work(tp->left) : 0;
        if( isFindErr ){ return 0; }
        int rdeep = tp->right ? work(tp->right) : 0;
        if( isFindErr ){ return 0; }
        
        int off = std::abs(ldeep-rdeep);

        if( off>1 ){ isFindErr = true; }
        return std::max(ldeep,rdeep) + 1;
    }


public:
    // 1 <= 树的结点个数 <= 10000 
    bool isBalanced( TreeNode* root ){

        if(!root){ return true; }

        work(root);
        return !isFindErr;
    
    }
};







//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: j55_11 :end ~~~~\n" );
}
}//~
