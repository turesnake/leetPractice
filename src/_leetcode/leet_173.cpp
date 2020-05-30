/*
 * ====================== leet_173.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 173. 二叉搜索树迭代器
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_173 {//~


// 25%， 6%
class BSTIterator{

    std::stack<TreeNode*> stk {};
    TreeNode *ptr   {nullptr};

public:

    BSTIterator( TreeNode* root ){
        ptr = root;
    }
    
    /** @return the next smallest number */
    int next() {
        // 取的是下一个，而不是本次的
        int val {};
        if( ptr || !stk.empty() ){
            while( ptr ){
                stk.push(ptr);
                ptr = ptr->left;
            }// 此时 ptr 指向某个 左子叶的 left（一个 nullptr）
            ptr = stk.top();
            stk.pop();
            val = ptr->val;
            ptr = ptr->right; 
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (ptr || !stk.empty());
    }


};




//=========================================================//
void main_(){

   TreeNode *t = create_a_tree({ 1,2 });

   BSTIterator b {t};

   debug::log( "{}", b.hasNext() );
   cout<<b.next()<<endl;

   debug::log( "{}", b.hasNext() );
   cout<<b.next()<<endl;

   debug::log( "{}", b.hasNext() );
   cout<<b.next()<<endl;

   debug::log( "{}", b.hasNext() );

    

    debug::log( "\n~~~~ leet: 173 :end ~~~~\n" );
}
}//~
