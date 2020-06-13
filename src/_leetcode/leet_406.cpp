/*
 * ====================== leet_406.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 406. 根据身高重建队列
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_406 {//~


// 贪心算法   50%  100%
// 优先处理处理那个 最矮的，如果它的前面有 n个，那么它一定排在 n+1 位置
// 然后从矮到高 逐个确认 

// 用小顶堆 来排序 

class S{

struct Elem{
    struct Greater{
        bool operator()( const Elem &a, const Elem &b ){
            if( a.h==b.h ){ return a.k>b.k; }
            return a.h>b.h;
        }
    };
    Elem()=default;
    int h {0};
    int k {0};
};

public:
    std::vector<std::vector<int>> reconstructQueue( std::vector<std::vector<int>>& people ){

        if( people.empty() ){ return {}; }

        int N = static_cast<int>(people.size());

        std::priority_queue<Elem,std::vector<Elem>,Elem::Greater> minHeap {};
        for( auto &v : people ){
            minHeap.push(Elem{v.at(0), v.at(1)});
        }

        std::vector<std::vector<int>> outs ( N, std::vector<int>{} );
        while( !minHeap.empty() ){
            auto elem = minHeap.top();
            minHeap.pop();
            int oi=0;// for outs
            for( int ki=0; ki<elem.k; ki++,oi++ ){
                for( ; !outs.at(oi).empty(); oi++ ){
                    if( outs.at(oi).at(0)>=elem.h ){ break; }
                } 
            }
            for( ; !outs.at(oi).empty(); oi++ ){}// 找到空位 
            // 现在，oi 指向 本elem，可以放置的位置
            outs.at(oi).push_back( elem.h );
            outs.at(oi).push_back( elem.k );
        }
        return outs;

    }
};



//=========================================================//
void main_(){

    

  


    
    debug::log( "\n~~~~ leet: 406 :end ~~~~\n" );
}
}//~
