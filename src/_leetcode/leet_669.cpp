/*
 * ====================== leet_669.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 669. 修剪二叉搜索树
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_669 {//~


// 递归
class Solution {

    int LL {};
    int RR {};
    // tp 一定非空
    TreeNode* work( TreeNode* tp ){
        int v = tp->val;
        if( v < LL ){
            return (tp->right) ? work(tp->right) : nullptr;
        }else if( v > RR ){
            return (tp->left)  ? work(tp->left)  : nullptr;
        }else{
            tp->left  = (tp->left)  ? work(tp->left)  : nullptr;
            tp->right = (tp->right) ? work(tp->right) : nullptr;
            return tp;
        }
    }
public:

    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if( !root ){ return nullptr; }
        LL = L;
        RR = R;
        return work(root);
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


    debug::log( "\n~~~~ leet: 669 :end ~~~~\n" );
}
}//~
