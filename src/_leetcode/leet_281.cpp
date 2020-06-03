/*
 * ====================== leet_281.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 281. 锯齿迭代器
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_281 {//~


// 53%, 100%
class Z{
    struct Elem{
        std::vector<int> *vp {};
        size_t N   {};
        size_t idx {};
    };

    std::vector<Elem> elems {};
    size_t idx {0};


public:
    Z( std::vector<int>& v1, std::vector<int>& v2) {
        elems.push_back(Elem{ &v1, v1.size(), 0 });
        elems.push_back(Elem{ &v2, v2.size(), 0 });
    }

    int next() {
        int val {};
        while( true ){
            auto &e = elems.at(idx);
            if(e.idx<e.N){
                val = e.vp->at(e.idx);
                e.idx++;
                idx++;
                if( idx>=elems.size() ){ idx=0; }
                break;// find
            }
            idx++;
            if( idx>=elems.size() ){ idx=0; }
        }
        return val;
    }

    bool hasNext() {
        for( auto &e : elems ){
            if( e.idx<e.N ){ return true; }
        }
        return false;
    }
};






//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 281 :end ~~~~\n" );
}
}//~
