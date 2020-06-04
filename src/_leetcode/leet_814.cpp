/*
 * ====================== leet_814.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.03
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 814. 二叉树剪枝
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_814 {//~

// 递归 76%, 100%
// 后续遍历 来减枝
class S{

    // ret: true = have 1
    // tp not null
    bool work( TreeNode *tp ){
        bool l = tp->left ? work(tp->left) : false;
        bool r = tp->right ? work(tp->right) : false;
        if(l){
            if(r){// 都保留 两儿子都裁剪
                return true;
            }else{// 只减 right
                tp->right = nullptr;
                return true;
            }
        }else{
            if(r){// 只减 left
                tp->left = nullptr;
                return true;
            }else{// 两儿子都没1
                
                if( tp->val==1 ){
                    tp->left = nullptr;
                    tp->right = nullptr;
                    return true;
                }else{
                    return false;//留到以后去减
                }
            }
        }
    }

public:

    TreeNode* pruneTree( TreeNode* root ){
        if(!root){ return nullptr; }
        bool ret = work(root);
        if( !ret ){ return nullptr; }// 全树无1
        return root;
    }

};


//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 814 :end ~~~~\n" );
}
}//~
