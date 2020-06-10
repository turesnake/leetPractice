/*
 * ====================== leet_145.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 145. 二叉树的后序遍历
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_145 {//~


// 递归
class S1{
    std::vector<int> elems {};
public:
    // tp 一定非 nullptr
    void work( TreeNode *tp ){
        if( tp->left  ){ work(tp->left); }
        if( tp->right ){ work(tp->right); }
        elems.push_back( tp->val );
    } 

    std::vector<int> postorderTraversal( TreeNode* root ){
        if( !root ){ return {}; }
        work(root);
        return elems;
    }
};


// 迭代（stack）
// 这个版本实现的并不好，几乎无法实用
class S2{
public:

    std::vector<int> postorderTraversal( TreeNode* root) {

        if( !root ){ return {}; }
        std::vector<int> elems {};
        std::stack<TreeNode*> stk {};
        stk.push( root );
        while( !stk.empty() ){
            TreeNode *tp = stk.top();
            stk.pop();
            elems.push_back(tp->val);
            if( tp->left  ){ stk.push(tp->left); }
            if( tp->right ){ stk.push(tp->right); }
        }
        std::reverse( elems.begin(), elems.end() );
        return elems;
    }
};



// 迭代
// 这个思路很绕：每次压入 父节点后，还要再压入一个 null，然后再压入 r，l
// 假设，r，l 都是 leaf。 那么，本来要读取 l 的回合，什么也不做，而是再压入一个 null
// 下一回合，识别到 top()==null,  成功读取，存放在 null 下方的一个元素（比如上文的 l）
// ---
// 如果 stk.top() 是个有效元素，想要读取它，就一定要先浪费一个回合，压入一个 null
// 然后走固定的流程，才能读取到这个 原来的 top 值
// ---
// 这会导致，父节点在被访问时，并不会被立刻pop。而是会先压入一个 null，然后再压入它的 r，l
// 这是，这个父节点 还存在于 stk 中
//
class S3{
public:

    std::vector<int> postorderTraversal( TreeNode* root) {

        if( !root ){ return {}; }
        std::vector<int> elems {};
        std::stack<TreeNode*> stk {};
        stk.push( root );

        while( !stk.empty() ){
            TreeNode *tp = stk.top();
            if( tp==nullptr ){
                stk.pop();
                elems.push_back( stk.top()->val );
                stk.pop();
            }else{
                stk.push(nullptr);
                if(tp->right){stk.push(tp->right);}// lr 倒置
                if(tp->left){stk.push(tp->left);}
            }
        }

        return elems;
    }
};







//=========================================================//
void main_(){

    TreeNode *t = create_a_tree( { 1,2,3,4,5,6,7 } );
    print_a_tree(t);
    cout << "\n======"<<endl;

    auto ret = S1{}.postorderTraversal( t );
    for( int i : ret ){ cout << i << ", "; }
    cout << endl;

    auto ret2 = S3{}.postorderTraversal( t );
    for( int i : ret2 ){ cout << i << ", "; }
    cout << endl;

    

    debug::log( "\n~~~~ leet: 145 :end ~~~~\n" );
}
}//~
