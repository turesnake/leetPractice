/*
 * ====================== leet_m17_12.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 17.12. BiNode
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m17_12 {//~


// 递归 52%， 100%
class S{
    TreeNode *out {};
    TreeNode *ptr {};
    // tp not null
    void work( TreeNode *tp ){
        TreeNode *l = tp->left;
        TreeNode *r = tp->right;
        if(l){work(l);}
        //---//
        tp->left = nullptr;
        ptr->right = tp;
        ptr = ptr->right;
        //---//
        if(r){work(r);}
    }
public:
    TreeNode* convertBiNode(TreeNode* root) {
        if(!root){ return nullptr; }
        out = new TreeNode (0); // sentry
        ptr = out;
        work(root);
        return out->right;
    }
};


//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: m17_12 :end ~~~~\n" );
}
}//~
