/*
 * ====================== leet_337.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.05
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 337. 打家劫舍 III
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_337 {//~


// 为每个节点，准备两个 状态值：
// -1- 包含自己时，最大和
// -2- 不包含自己时，最大和


// 如果选择递归，可以省去 显式地存储 树中各节点状态的 麻烦


// 递归  95%  98%
class S{

struct Ret{
    int with    {0};// 包含本节点值 的最大值
    int notWith {0};// 不包含本节点值 的最大值
};

    // tp 一定非空
    Ret rec( TreeNode* tp ){

        Ret retl = tp->left ? rec(tp->left) : Ret{};
        Ret retr = tp->right ? rec(tp->right) : Ret{};

        Ret r {};
        r.with = retl.notWith + retr.notWith + tp->val;
        r.notWith = std::max(retl.with, retl.notWith) + 
                    std::max(retr.with, retr.notWith);
        return r;
    }

public:
    int rob( TreeNode* root ){
        if(!root){ return 0; }
        Ret r = rec( root );
        return std::max( r.with, r.notWith );
    }

};



//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 337 :end ~~~~\n" );
}
}//~
