/*
 * ====================== leet_m55_1.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.28
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题55 - I. 二叉树的深度
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_m55_1 {//~



// 计算最大深度
int maxDepth( TreeNode* root ) {
    if( !root ){ return 0; }
    if( !root->left && !root->right ){ return 1; }
    int ld {0};
    int rd {0};
    if( root->left ){ ld=maxDepth(root->left); }
    if( root->right ){ rd=maxDepth(root->right); }
    return std::max(ld,rd)+1;
}



//=========================================================//
void main_(){

    int Nil {INT_MIN};
    //std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    //std::vector<int> inputs { 1,2,2,3,3,Nil,Nil,4,4 };
    //std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    std::vector<int> inputs { 1,2,3,4,5 };

    TreeNode *treeRoot = create_a_tree( inputs );
    print_a_tree( treeRoot );
    cout << endl;

    auto deep = maxDepth( treeRoot );
    debug::log( "deep = {}", deep );


    debug::log( "\n~~~~ leet: m55_1 :end ~~~~\n" );
}
}//~
