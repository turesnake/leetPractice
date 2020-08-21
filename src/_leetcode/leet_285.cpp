/*
 * ====================== leet_285.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 285. 二叉搜索树中的顺序后继
 */
#include "innLeet.h"
#include "TreeNode1.h"




namespace leet_285 {//~




//   32%  15%
class S{
    TreeNode* ans {nullptr};
    int tgt {};

    // tp not nullptr
    void work( TreeNode* tp ){
        if( tp->val <= tgt ){
            if( tp->right ){ work( tp->right ); }
        }else{
            if( ans ){
                if( tp->val < ans->val ){
                    ans = tp;
                }
            }else{
                ans = tp;
            }
            if( tp->left ){ work( tp->left ); }
        }
    }

public:
    // 树每个节点值 都是唯一的
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        if( !root ){ return nullptr; }
        tgt = p->val;
        work(root);
        return ans ? ans : nullptr;

    }
};



//=========================================================//
void main_(){





    

    debug::log( "\n~~~~ leet: 285 :end ~~~~\n" );
}
}//~
