/*
 * ====================== leet_563.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 563. 二叉树的坡度
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_563 {//~



// 递归 67%, 25%
class S{

    int sum {0};

    // 后序遍历
    // tp非空
    // ret 本树节点之和
    int work( TreeNode *tp ){
        int l = (tp->left) ? work(tp->left) : 0;
        int r = (tp->right) ? work(tp->right) : 0;
        sum += std::abs(l-r);
        return tp->val + l + r;
    }

public:
    int findTilt(TreeNode* root) {
        if(!root){ return 0; }
        work(root);
        return sum;
    }
};





//=========================================================//
void main_(){


    

    debug::log( "\n~~~~ leet: 563 :end ~~~~\n" );
}
}//~
