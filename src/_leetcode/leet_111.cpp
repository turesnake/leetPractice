/*
 * ====================== leet_111.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 111. 二叉树的最小深度
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_111 {//~



// 最浅叶节点深度
int minDepth( TreeNode* root ) {
    if( !root ){ return 0; }
    if( !root->left && !root->right ){ return 1; }
    int ld {INT_MAX};
    int rd {INT_MAX};
    if( root->left ){ ld=minDepth(root->left); }
    if( root->right ){ rd=minDepth(root->right); }
    return std::min(ld,rd)+1;
}



//=========================================================//
void main_(){

    int Nil {INT_MIN};
    std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    //std::vector<int> inputs { 1,2,2,3,3,Nil,Nil,4,4 };
    //std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    //std::vector<int> inputs { 1,2,3,4,5 };

    TreeNode *treeRoot = create_a_tree( inputs );
    print_a_tree( treeRoot );
    cout << endl;

    auto deep = minDepth( treeRoot );
    debug::log( "deep = {}", deep );


    debug::log( "\n~~~~ leet: 111 :end ~~~~\n" );
}
}//~
