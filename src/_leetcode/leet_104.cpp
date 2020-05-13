/*
 * ====================== leet_104.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 104. 二叉树的最大深度
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_104 {//~



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
void leet_104_main(){

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


    debug::log( "\n~~~~ leet: 104 :end ~~~~\n" );
}
}//~
