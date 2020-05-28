/*
 * ====================== leet_404.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 404. 左叶子之和
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_404 {//~



class S{

    int sum {0};
    // tp 一定非空
    void work( TreeNode* tp, bool isLeft ){
        if( isLeft && !tp->left && !tp->right ){
            sum += tp->val;
            return;
        }
        if( tp->left ){ work(tp->left,true); }
        if( tp->right ){ work(tp->right,false); }
    }


public:

    int sumOfLeftLeaves(TreeNode* root){
        if( !root ){ return 0; }
        work(root,false);// 树只有根节点有元素时，不算左叶子
        return sum;
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


    debug::log( "\n~~~~ leet: 404 :end ~~~~\n" );
}
}//~
