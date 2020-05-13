/*
 * ====================== leet_226.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 226. 翻转二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_226 {//~




TreeNode* invertTree( TreeNode* root ){

    if( !root ){ return nullptr; }
    std::swap( root->left, root->right );
    invertTree(root->left);
    invertTree(root->right);
    return root;
}





//=========================================================//
void main_(){

    int Nil {INT_MIN};

    std::vector<int> inputs { 4,2,7,1,3,Nil,9 };
    TreeNode *treeRoot = create_a_tree( inputs );
    print_a_tree( treeRoot );
    cout << endl;

    auto ret = invertTree( treeRoot );
    print_a_tree( treeRoot );
    cout << endl;








    debug::log( "\n~~~~ leet: 226 :end ~~~~\n" );
}
}//~
