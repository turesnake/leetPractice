/*
 * ====================== leet_114.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 114. 二叉树展开为链表
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_114 {//~


// 前序遍历，递归版
class S{
    TreeNode *head {};
    TreeNode *p {};
    void work(TreeNode *tp ){
        TreeNode *l = tp->left;
        TreeNode *r = tp->right;
        tp->left = nullptr;
        p->right = tp;
        p = p->right;
        if(l){ work(l); }
        if(r){ work(r); }
    }
public:
    void flatten(TreeNode* root ){
        if(!root){ return; }
        head = new TreeNode(0);
        p = head;
        work(root);
        return;
    }
};





//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 114 :end ~~~~\n" );
}
}//~
