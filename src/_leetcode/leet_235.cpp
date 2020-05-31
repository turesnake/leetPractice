/*
 * ====================== leet_235.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 235. 二叉搜索树的最近公共祖先
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_235 {//~


// 那个节点开始，把两个值 分叉了，那么节点，就是 最近公共祖先
class S{
public:
    TreeNode* lowestCommonAncestor( TreeNode* root, TreeNode* p, TreeNode* q ){
        int vp = p->val;
        int vq = q->val;
        TreeNode *ptr = root;
        while( ptr ){
            int v = ptr->val;
            if( v==vp || v==vq ||
                (vp<v && vq>v) ||
                (vp>v && vq<v) ){ return ptr; }
            ptr = (vp<v) ? ptr->left : ptr->right;
        }
        return nullptr; // never reach
    }
};



//=========================================================//
void main_(){


    

    debug::log( "\n~~~~ leet: 235 :end ~~~~\n" );
}
}//~
