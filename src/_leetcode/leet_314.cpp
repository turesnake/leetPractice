/*
 * ====================== leet_314.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 314. 二叉树的垂直遍历
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_314 {//~



void work2(     TreeNode* root, 
                int     lvl,
                int     treeIdx,
                std::map<int,std::map<int,int>> &mps ){
    if( !root ){ return; }
    // insert vals
    if( root->left ){
        auto [it,bl] = mps.emplace(lvl-1, std::map<int,int>{});//maybe
        it->second.emplace( treeIdx*2, root->left->val );
    }
    if( root->right ){
        auto [it,bl] = mps.emplace(lvl+1, std::map<int,int>{});//maybe
        it->second.emplace( treeIdx*2+1, root->right->val );
    }
    // recursive
    if( root->left ){ work2( root->left, lvl-1, treeIdx*2, mps ); }
    if( root->right ){ work2( root->right, lvl+1, treeIdx*2+1, mps ); }
}



std::vector<std::vector<int>> verticalOrder( TreeNode* root ) {
    std::vector<std::vector<int>> outs {}; 
    if( !root ){ return outs; } 
    std::map<int,std::map<int,int>> mps {}; // <treeIdx, val>
    // 提前在外部完成 root.val 的压入
    auto [insertIt,insertBool] = mps.emplace(0, std::map<int,int>{});
    insertIt->second.emplace( 1, root->val );
    // do work
    work2( root, 0, 1, mps );
    for( const auto &pair1 : mps ){
        outs.push_back( std::vector<int>{} );
        auto &v = outs.back();
        for( const auto &pair2 : pair1.second ){
            v.push_back( pair2.second );
        }
    }
    return outs;
}




//=========================================================//
void main_(){

    int Nil {INT_MIN};

    //std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    //std::vector<int> inputs { 1,2,2,3,3,Nil,Nil,4,4 };
    //std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    //std::vector<int> inputs { 1,2,3,4,5 };

    //std::vector<int> inputs { 3,9,20,Nil,Nil,15,7 };
    //std::vector<int> inputs { 3,9,8,4,0,1,7 };
    std::vector<int> inputs { 3,9,8,4,0,1,7,Nil,Nil,Nil,2,5 };

    TreeNode *treeRoot = create_a_tree( inputs );
    print_a_tree( treeRoot );
    cout << endl;

    auto outs = verticalOrder( treeRoot );
    for( const auto &v : outs ){
        cout << "[ ";
        for( const auto &i : v ){
            cout << i << ", ";
        }
        cout << " ]" << endl;
    }


    debug::log( "\n~~~~ leet: 314 :end ~~~~\n" );
}
}//~
