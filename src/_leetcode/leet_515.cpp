/*
 * ====================== leet_515.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 515. 在每个树行中找最大值
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_515 {//~


// bfs 27%, 25%
struct Elem{
    TreeNode    *tp {nullptr};
    int         deep {}; // 层, 0 代表第一层
};

std::vector<int> largestValues( TreeNode* root ){

    if( !root ){ return {}; }

    std::vector<int> maxs {};
    std::deque<Elem> que {};
    que.push_back( Elem{root, 0} );

    while( !que.empty() ){

        auto &elem = que.front();

        while( static_cast<int>(maxs.size()) < (elem.deep+1) ){
            maxs.push_back(INT_MIN);
        }
        maxs.at(elem.deep) = std::max( maxs.at(elem.deep), elem.tp->val );

        if( elem.tp->left  ){ que.push_back( Elem{ elem.tp->left, elem.deep+1 } ); }
        if( elem.tp->right ){ que.push_back( Elem{ elem.tp->right, elem.deep+1 } ); }
        que.pop_front();
    }
    return maxs;
}



//=========================================================//
void main_(){



    //TreeNode *t = create_a_tree( { 1,3,2,5,3,niln,9 } );
    TreeNode *t = create_a_tree( { 1 } );
    print_a_tree( t );

    auto ret = largestValues( t );

    cout <<"ret:"<<endl;
    for( int i : ret ){
        cout <<i<<", ";
    }
    cout <<endl;

  


    debug::log( "\n~~~~ leet: 515 :end ~~~~\n" );
}
}//~
