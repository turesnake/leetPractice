/*
 * ===================== leet_629.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 692. 前K个高频单词
 */
#include "innLeet.h"


namespace leet_629 {//~



//   66%   75%
class S{

struct Elem{
    int num {};
    const std::string *strp {nullptr};
};

struct ElemLess{
    bool operator()( Elem a, Elem b ){
        if( a.num==b.num ){
            return (*a.strp) > (*b.strp);
        }
        return a.num < b.num;
    }
};


public:
    // 1<= k <= len
    std::vector<std::string> topKFrequent( std::vector<std::string>& words, int k ){


        std::unordered_map<std::string,int> umap {};
        for( const auto &word : words ){
            umap[word]++;
        }
        //---//
        std::priority_queue<Elem,std::vector<Elem>,ElemLess> maxHeap {};
        for( auto &[s,n] : umap ){
            maxHeap.push(Elem{ n, &s });
        }
        //---//
        std::vector<std::string> outs {};
        for( int i=0; i<k; i++ ){
            outs.push_back( *maxHeap.top().strp );
            maxHeap.pop();
        }
        return outs;

    }
};






//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 629 :end ~~~~\n" );
}
}//~
