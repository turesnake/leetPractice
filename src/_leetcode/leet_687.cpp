/*
 * ====================== leet_687.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 687. 最长同值路径
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_687 {//~




class S{

    int maxSum {0};
    // tp 一定非空
    int work( TreeNode* tp, int parentVal ){
        int lv = (!tp->left)  ? 0 : work(tp->left,tp->val);
        int rv = (!tp->right) ? 0 : work(tp->right,tp->val);
        maxSum = std::max( maxSum, lv+rv+1 );
        return (tp->val==parentVal) ? std::max(lv,rv)+1 : 0;
    }

public:

    int longestUnivaluePath( TreeNode* root ){
        if( !root ){ return 0; }
        work( root,0);// 此处的 0 无意义
        return maxSum-1;
    }
};




//=========================================================//
void main_(){


    
    std::vector<int> v { 3,3,3 };

    TreeNode *t = create_a_tree( v );
    print_a_tree( t );
    cout << endl;


    auto ret = S{}.longestUnivaluePath( t );
    cout<<"ret: " << ret<< endl;


    debug::log( "\n~~~~ leet: 687 :end ~~~~\n" );
}
}//~
