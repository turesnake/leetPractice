/*
 * ====================== leet_102.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 102. 二叉树的层序遍历
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_102 {//~





void lvlWork(   TreeNode* root, 
                int     deep,
                std::vector<std::vector<int>> &outs ){

    if( !root ){ return; }
    while( static_cast<int>(outs.size()) < deep ){
        outs.push_back( std::vector<int>{} );
    }
    if( root->left ){ lvlWork( root->left, deep+1, outs ); }
    outs.at(deep-1).push_back( root->val );
    if( root->right ){ lvlWork( root->right, deep+1, outs ); }
}



std::vector<std::vector<int>> levelOrder( TreeNode* root ){
    std::vector<std::vector<int>> outs {};
    lvlWork( root, 1, outs );
    return outs;
}




//=========================================================//
void main_(){

    int Nil {INT_MIN};
    //std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    std::vector<int> inputs { 1,2,2,3,3,Nil,Nil,4,4 };
    //std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    //std::vector<int> inputs { 1,2,3,4,5 };

    TreeNode *treeRoot = create_a_tree( inputs );
    //TreeNode *treeRoot {nullptr};
    print_a_tree( treeRoot );
    cout << endl;

    auto outs = levelOrder( treeRoot );
    for( const auto &v : outs ){
        cout << "[ ";
        for( const auto &i : v ){
            cout << i << ", ";
        }
        cout << " ]" << endl;
    }


    debug::log( "\n~~~~ leet: 102 :end ~~~~\n" );
}
}//~
