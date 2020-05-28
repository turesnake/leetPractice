/*
 * ====================== leet_94.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 94. 二叉树的中序遍历
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_94 {//~


// 对一个 bst 进行中序遍历，可以获得 一串从小到大的有序数据链




// 递归
class S1{
    std::vector<int> elems {};
    // tp 一定非空
    void work( TreeNode *tp ){
        if( tp->left ){ work(tp->left); }
        elems.push_back(tp->val);
        if( tp->right ){ work(tp->right); }
    }
public:
    std::vector<int> inorderTraversal( TreeNode* root ){
        if( !root ){ return {}; }
        work(root);
        return elems;
    }
};




// 迭代 stack，不如下一版 更容易理解
// 在 ptr遍历某个 节点的 right 时，此节点已经从 stk 中 pop 了
// 所以，就算把 right 遍历完，回头从 stk 中取出的节点，也是 此节点的父节点
class S2{
public:
    std::vector<int> inorderTraversal( TreeNode* root ){
        
        std::vector<int> elems {};
        std::stack<TreeNode*> stk {};
        // 这个过程不好理解...
        TreeNode *ptr = root; 
        while( ptr!=nullptr || !stk.empty() ){
            while( ptr!=nullptr ){
                stk.push(ptr);
                ptr = ptr->left;
            }
            ptr = stk.top();
            stk.pop();// 现在，stk.top 变成了 ptr 的 父节点
            elems.push_back( ptr->val );
            ptr = ptr->right; // maybe nullptr
        }
        return elems;
    }
};


// 迭代 stack 更容易理解版
class S3{
public:
    std::vector<int> inorderTraversal( TreeNode* root ){
        
        std::vector<int> elems {};
        std::stack<TreeNode*> stk {};
        TreeNode *ptr = root; 
        while( ptr!=nullptr || !stk.empty() ){
            if( ptr!=nullptr ){
                // 此时，ptr 指向某个有效节点，需要继续探索 left 直到遇到 null
                stk.push(ptr);
                ptr = ptr->left;
            }else{
                // 此时，ptr == stk.top()->left，一个 null 值
                elems.push_back( stk.top()->val );
                ptr = stk.top();
                stk.pop();// 现在，stk.top 变成了 ptr 的 父节点
                ptr = ptr->right; // maybe nullptr
            }
        }
        return elems;
    }
};








//=========================================================//
void main_(){

    //TreeNode *t = create_a_tree( { 1,2,3,4,5,6,7 } );
    TreeNode *t = create_a_tree( {  } );
    print_a_tree(t);
    cout << "\n======"<<endl;

    auto ret = S3{}.inorderTraversal( t );

    for( int i : ret ){
        cout << i << ", ";
    }
    cout <<endl;
    

    debug::log( "\n~~~~ leet: 94 :end ~~~~\n" );
}
}//~
