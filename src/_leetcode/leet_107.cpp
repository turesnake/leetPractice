/*
 * ====================== leet_107.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 107. 二叉树的层次遍历 II
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_107 {//~


class S{

struct Elem{
    TreeNode    *tp {nullptr};
    int         deep {0}; //base on 0
};

public:


    std::vector<std::vector<int>> levelOrderBottom( TreeNode* root ){

        if( !root ){ return {}; }
        std::deque<Elem> que { Elem{root,0} };
        std::vector<std::vector<int>> elems {};
        while( !que.empty() ){
            auto [tp,deep] = que.front(); 
            while( static_cast<int>(elems.size()) < deep+1 ){
                elems.push_back( std::vector<int>{} );
            }
            elems.at(deep).push_back( tp->val );
            //--
            if( tp->left  ){ que.push_back( Elem{ tp->left,  deep+1 } ); }
            if( tp->right ){ que.push_back( Elem{ tp->right, deep+1 } ); }
            que.pop_front();
        }
        std::reverse( elems.begin(), elems.end() );
        return elems;
    }
    
};



//=========================================================//
void main_(){

    
    //TreeNode *t = create_a_tree( { 3,9,20,niln,niln,15,7 } );
    TreeNode *t = create_a_tree( { 8,9 } );
    print_a_tree( t );
    cout << "\n===========" << endl;

    auto ret = S{}.levelOrderBottom(t);
    for( auto &c : ret ){
        for( int i : c ){
            cout << i << ", ";
        }
        cout << endl;
    }
    


    debug::log( "\n~~~~ leet: 107 :end ~~~~\n" );
}
}//~
