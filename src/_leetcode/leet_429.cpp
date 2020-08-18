/*
 * ====================== leet_429.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 429. N叉树的层序遍历
 */
#include "innLeet.h"
#include "NTree1.h"


namespace leet_429 {//~



// bfs
class S{

    struct Elem{
        NNode    *tp {nullptr};
        int     deep {0}; //base on 0
    };

public:

    std::vector<std::vector<int>> levelOrder( NNode* root ){

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
            for( NNode *cp : tp->children ){
                if( cp ){ que.push_back( Elem{cp,deep+1} ); }
            }
            que.pop_front();
        }
        return elems;
    }

};





//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 429 :end ~~~~\n" );
}
}//~
