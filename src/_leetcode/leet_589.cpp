/*
 * ====================== leet_589.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 589. N叉树的前序遍历
 */
#include "innLeet.h"
#include "NTree1.h"


namespace leet_589 {//~



// 递归
class S1{
    std::vector<int> elems {};
public:
    // root 一定非 nullptr
    void work( Node *tp ){
        elems.push_back( tp->val );
        for( Node *cp : tp->children ){
            if( cp ){ work(cp); }
        }
    } 

    std::vector<int> preorder( Node* root ){
        if( !root ){ return {}; }
        work(root);
        return elems;
    }
};


// 迭代（stack）
class S2{
public:
    std::vector<int> preorder( Node* root ){

        if( !root ){ return {}; }
        std::vector<int> elems {};
        std::stack<Node*> stk {};
        stk.push( root );
        while( !stk.empty() ){
            Node *tp = stk.top();
            stk.pop();
            elems.push_back(tp->val);
            int N = static_cast<int>(tp->children.size());
            for( int i=N-1; i>=0; i-- ){
                if( tp->children.at(i) ){ stk.push(tp->children.at(i)); }
            }
        }
        return elems;
    }
};







//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 589 :end ~~~~\n" );
}
}//~
