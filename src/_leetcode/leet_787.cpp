/*
 * ====================== leet_787.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 787. K 站中转内最便宜的航班
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_787 {//~


// 最短路径算法 Dijks

// key = head*100 + tail;



//   未完成 ...




class S{

struct P{
    int  price {INT_MAX};
    bool isSet {false};
};
struct Elem{
    int dst {};
    int price {};
};
struct QElem{
    int src {};
    int deep {};// <K
};


public:
    // n 范围是 [1, 100]，城市标签从 0 到 n-1.
    // 航班数量范围是 [0, n * (n - 1) / 2].
    // 每个航班的格式 (src, dst, price).
    // 每个航班的价格范围是 [1, 10000].
    // k 范围是 [0, n-1].
    // 航班没有重复，且不存在环路
    // 如果 无法按要求到达，返回 -1
    int findCheapestPrice( int n, std::vector<std::vector<int>>& flights, int src, int dst, int K ){

        std::vector<P> prices (n, P{});
        prices[src].price = 0; // 起点为 0

        std::vector<std::vector<Elem>> adjs (n, std::vector<Elem>{});//邻接表
        for( auto &e : flights ){
            adjs[e[0]].push_back( Elem{e[1],e[2]} );
        }

        std::deque<QElem> que { QElem{src,0} };

        while( !que.empty() ){
            auto [tsrc, deep] = que.front();
            que.pop_front();

            if( deep>K ){ continue; }

            prices[tsrc].isSet = true;

            for( auto &e : adjs[tsrc] ){
                if( prices[e.dst].isSet ){ continue; }

                prices[e.dst].price = std::min( prices[e.dst].price, prices[tsrc].price + e.price );
                que.push_back( QElem{ e.dst, deep+1 } );
            }
        }

        if( prices[dst].price==INT_MAX ){ return -1; }
        return  prices[dst].price;


    }
};



//=========================================================//
void main_(){

    



    debug::log( "\n~~~~ leet: 787 :end ~~~~\n" );
}
}//~
