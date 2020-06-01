/*
 * ====================== leet_333.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 333. 最大 BST 子树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_333 {//~



// 元素相等 也不构成 bst 16%， 50%
// 可能是返回值太重了，导致效率不高 
class S{

    struct Ret{
        bool isBST {};
        int  sum {};// 累加的 bst节点数
        int  minv {}; 
        int  maxv {};
    };

    int mmax {0};

    // tp非空
    Ret work( TreeNode *tp ){

        int selfV = tp->val;
        TreeNode *l = tp->left;
        TreeNode *r = tp->right;
        Ret retL = (l) ? work(l) : Ret{true,0,0,0};
        Ret retR = (r) ? work(r) : Ret{true,0,0,0};

        // 本层，或某个子树不是 bst
        if( !retL.isBST || 
            !retR.isBST ||
            (l && retL.maxv>=selfV) || 
            (r && retR.minv<=selfV)  
        ){ return Ret{false,0,0,0}; }

        Ret rett { true,0,0,0 };
        int sum = retL.sum + retR.sum + 1;
        mmax = std::max( mmax, sum );
        rett.sum = sum;
        rett.minv = (l) ? retL.minv : selfV;
        rett.maxv = (r) ? retR.maxv : selfV;
        return rett;
    }

public:
    int largestBSTSubtree( TreeNode* root) {
        if(!root){ return 0; }
        work(root);
        return mmax;
    }
};




//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: 333 :end ~~~~\n" );
}
}//~
