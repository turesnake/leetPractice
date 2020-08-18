/*
 * ====================== leet_559.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.26
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 559. N叉树的最大深度
 */
#include "innLeet.h"
#include "NTree1.h"


namespace leet_559 {//~



// bfs
class S{

    struct Elem{
        NNode    *tp {nullptr};
        int     deep {1}; //base on 1
    };

public:

    int maxDepth( NNode* root ){

        if( !root ){ return 0; }
        std::deque<Elem> que { Elem{root,1} };
        int maxDeep {INT_MIN};
        while( !que.empty() ){
            auto [tp,deep] = que.front(); 
            maxDeep = std::max( maxDeep, deep );
            for( NNode *cp : tp->children ){
                if( cp ){ que.push_back( Elem{cp,deep+1} ); }
            }
            que.pop_front();
        }
        return maxDeep;
    }

};





//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 559 :end ~~~~\n" );
}
}//~
