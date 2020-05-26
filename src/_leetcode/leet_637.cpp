/*
 * ====================== leet_637.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 637. 二叉树的层平均值
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_637 {//~


class S{

struct Elem{
    TreeNode    *tp {nullptr};
    int         deep {0}; //base on 0
};

public:
    
    
    std::vector<double> averageOfLevels( TreeNode* root) {

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
        int N = static_cast<int>(elems.size());
        std::vector<double> outs ( N );
        for( int n=0; n<N; n++ ){
            const auto &c = elems.at(n);
            double sum {0.0};
            for( int i : c ){ 
                sum += static_cast<double>(i); 
            }
            outs.at(n) = sum / static_cast<double>(c.size());
        }
        return outs;
    }



};



//=========================================================//
void main_(){

    /*
    TreeNode *t = create_a_tree( { 3 } );
    print_a_tree( t );
    cout << endl;

    auto ret = S{}.averageOfLevels(t);
    for( auto i : ret ){
        debug::log( "  {}", i );
    }
    */


    std::vector<int> tt { 1,2,3,4,5 };

    std::reverse( tt.begin(), tt.end() );
    for( int i : tt ){
        cout << i << ", ";
    }
    cout<< endl;




    debug::log( "\n~~~~ leet: 637 :end ~~~~\n" );
}
}//~
