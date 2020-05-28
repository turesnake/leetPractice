/*
 * ====================== leet_538.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 538. 把二叉搜索树转换为累加树
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_538 {//~



// 倒置的 中序遍历 26% 7%
class Solution {
    int sum = 0;
    // tp 一定非空
    void work( TreeNode* tp ){
        if( tp->right ){ work(tp->right); }
        tp->val += sum;
        sum = tp->val;
        if( tp->left ){ work(tp->left); }
    }
public:
    TreeNode* convertBST( TreeNode* root ){
        if( !root ){ return nullptr; }
        work( root );
        return root;
    }
};



//=========================================================//
void main_(){


    
    std::vector<int> v { 3,3,3 };

    TreeNode *t = create_a_tree( v );
    print_a_tree( t );
    cout << endl;


    //auto ret = S{}.longestUnivaluePath( t );
    //cout<<"ret: " << ret<< endl;


    debug::log( "\n~~~~ leet: 538 :end ~~~~\n" );
}
}//~
