/*
 * ====================== leet_257.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 257. 二叉树的所有路径
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_257 {//~

// ===== 1 =====
// 粗暴的办法，需要的字符串，每次递归都传值，同时在中途合并
void doo(   TreeNode* root_,
            std::string s_,
            std::vector<std::string> &strs_ ){
    // root_ must not nullptr
    s_ += std::to_string(root_->val);
    if( !root_->left && !root_->right ){
        strs_.push_back( std::move(s_) ); // final
        return;
    }
    if( root_->left ){ doo( root_->left, s_+"->", strs_ ); }
    if( root_->right ){ doo( root_->right, s_+"->", strs_ ); }
}
std::vector<std::string> binaryTreePaths( TreeNode* root ) {
    std::vector<std::string> strs {};
    if( !root ){ return strs; }
    doo( root, std::string{}, strs  );
    return strs;
}


// ===== 2 =====
// 用一个 deque 来维护当前遍历的数据
// 只在 leave 做字符串整合
void doo2(   TreeNode* root_,
            std::vector<int> &vals_,
            std::vector<std::string> &strs_ ){

    // root_ must not nullptr
    vals_.push_back(root_->val);
    if( !root_->left && !root_->right ){
        std::string s {};
        for( size_t i=0; i<vals_.size(); i++ ){
            if( i != 0 ){ s += "->"; }
            s += std::to_string(vals_.at(i));
        }
        strs_.push_back( std::move(s) );
        vals_.pop_back();
        return;
    }
    if( root_->left ){ doo2( root_->left, vals_, strs_ ); };
    if( root_->right ){ doo2( root_->right, vals_, strs_ );};
    vals_.pop_back();
}



std::vector<std::string> binaryTreePaths_2( TreeNode* root ) {

    std::vector<std::string> strs {};
    if( !root ){ return strs; }
    std::vector<int> vals {};
    doo2( root, vals, strs  );
    return strs;
}



//=========================================================//
void main_(){

    int Nil {INT_MIN};

    std::vector<int> inputs { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
    TreeNode *treeRoot = create_a_tree( inputs );
    //TreeNode *treeRoot = nullptr;
    print_a_tree( treeRoot );
    cout << endl;

    //---

    auto ret = binaryTreePaths_2( treeRoot );
    for( const auto &s : ret ){
        cout << s << endl;
    }
    





    debug::log( "\n~~~~ leet: 257 :end ~~~~\n" );
}
}//~
