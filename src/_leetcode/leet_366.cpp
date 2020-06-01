/*
 * ====================== leet_366.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 366. 寻找二叉树的叶子节点
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_366 {//~


// 后续遍历 100%,100%
class S{

    std::vector<std::vector<int>> outs {};

    // tp 非空
    // return： 本层离 leaf 的距离
    int work( TreeNode *tp ){
        int l = (tp->left) ? work(tp->left) : -1;
        int r = (tp->right) ? work(tp->right) : -1;
        int self = std::max(l,r) + 1;
        while( static_cast<int>(outs.size()) < self+1 ){
            outs.push_back( std::vector<int>{} );
        }
        outs.at(self).push_back(tp->val);
        return self;
    }

public:

    std::vector<std::vector<int>> findLeaves( TreeNode* root ){
        if(!root){ return {}; }
        work(root);
        return outs;
    }

};





//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: 366 :end ~~~~\n" );
}
}//~
