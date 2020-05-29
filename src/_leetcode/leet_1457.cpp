/*
 * ====================== leet_1457.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1457. 二叉树中的伪回文路径
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1457 {//~



// 递归 44%, 100%
class S2{
    std::vector<int> road {};//[0]空置 只使用 [1,9]
                        // 记录在某条路径中，每个数字 出现次数 
    int out {0};
    void check(){
        int oddNums = 0;
        for( int i : road ){
            if( i%2!=0 ){ oddNums++; }
        }
        if( oddNums<=1 ){ 
            out++; 
        }
    }
    // 递归 tp 一定非空
    void rec( TreeNode *tp ){
        road.at(tp->val)++;
        if( !tp->left && !tp->right ){//leaf
            check();
            road.at(tp->val)--;
            return;
        }
        if(tp->left){ rec(tp->left); }
        if(tp->right){ rec(tp->right); }
        road.at(tp->val)--;
    }   
public:
    int pseudoPalindromicPaths ( TreeNode* root ){
        road.resize( 10,0 );
        if(!root){ return 0; }
        rec(root);
        return out;
    }
};




//=========================================================//
void main_(){

    TreeNode *t = create_a_tree( {2,3,1,3,1,niln,1} );

    cout << S2{}.pseudoPalindromicPaths(t) << endl;


    debug::log( "\n~~~~ leet: 1457 :end ~~~~\n" );
}
}//~
