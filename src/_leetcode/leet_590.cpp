/*
 * ====================== leet_590.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 590. N叉树的后序遍历
 */
#include "innLeet.h"
#include "NTree1.h"


namespace leet_590 {//~



// 递归
class S1{
    std::vector<int> elems {};

    // root 一定非 nullptr
    void work( Node *tp ){
        for( Node *cp : tp->children ){
            if( cp ){ work(cp); }
        }
        elems.push_back( tp->val );
    } 

public:
    std::vector<int> postorder( Node* root ){
        if( !root ){ return {}; }
        work(root);
        return elems;
    }
};


// 迭代（stack）
class S2{
public:
    std::vector<int> postorder( Node* root ){

        if( !root ){ return {}; }
        std::vector<int> elems {};
        std::stack<Node*> stk {};
        stk.push( root );
        while( !stk.empty() ){
            Node *tp = stk.top();
            stk.pop();
            elems.push_back(tp->val);
            int N = static_cast<int>(tp->children.size());
            for( int i=0; i<N; i++ ){
                if( tp->children.at(i) ){ stk.push(tp->children.at(i)); }
            }
        }
        std::reverse( elems.begin(), elems.end() );
        return elems;
    }
};







//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 590 :end ~~~~\n" );
}
}//~
