/*
 * ====================== leet_98.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.31
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 98. 验证二叉搜索树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_98 {//~


// 递归
class S{

struct Ret{
    int mmin {};
    int mmax {};
    bool isValid {true};
};

    // tp 不为空
    Ret work( TreeNode *tp ){
        int v = tp->val;
        Ret ret {v,v,true};
        if(tp->left){
            if( tp->left->val>=v ){ return Ret{0,0,false}; }
            Ret l = work(tp->left);
            if( !l.isValid || l.mmax>=v){ return Ret{0,0,false}; }
            ret.mmin = l.mmin;
        }
        if(tp->right){
            if( tp->right->val<=v ){ return Ret{0,0,false}; }
            Ret r = work(tp->right);
            if( !r.isValid || r.mmin<=v ){ return Ret{0,0,false}; }
            ret.mmax = r.mmax;
        }
        return ret;
    }


public:
    bool isValidBST(TreeNode* root) {
        if( !root ){ return true; }
        return work(root).isValid;
    }
};



//=========================================================//
void main_(){
    

    debug::log( "\n~~~~ leet: 98 :end ~~~~\n" );
}
}//~
