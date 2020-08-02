/*
 * ====================== leet_1514.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1514. 概率最大的路径
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1514 {//~


// 用 dijkstra 的变种版 来做


//   31%   28%
class S{

struct HE{
    int    elem {};
    double w {};
};
struct HEGreater{
    bool operator()( HE a, HE b )const noexcept{
        return a.w < b.w;
    }
};

public:
    // n个节点，从0开始
    // 如果不存在从 start 到 end 的路径，请 返回 0 
    // 2 <= n <= 10^4
    // 0 <= start, end < n
    // start != end
    // 0 <= a, b < n
    // a != b
    // 0 <= succProb.length == edges.length <= 2*10^4
    // 0 <= succProb[i] <= 1
    // 每两个节点之间最多有一条边
    double maxProbability( int n, std::vector<std::vector<int>>& edges, 
                            std::vector<double>& succProb, int start, int end ){


        int Ne = static_cast<int>(edges.size());

        std::vector<char> vis (n,0);
        std::vector<double> weights (n, -9.9 );// 其实不会大于 1.0
        weights[start] = 1.0;

        std::vector<std::vector<HE>> adjs (n, std::vector<HE>{});

        for( int i=0; i<Ne; i++ ){
            int a = edges[i][0];
            int b = edges[i][1];
            adjs[a].push_back( HE{ b, succProb[i] } );
            adjs[b].push_back( HE{ a, succProb[i] } );
        }

        std::priority_queue<HE,std::vector<HE>,HEGreater> minHeap {};
        minHeap.push( HE{ start, 1.0 } );

        while( !minHeap.empty() ){
            auto [tsrc, tw] = minHeap.top();
            minHeap.pop();
            //---//
            if( vis[tsrc]==1 || tw!=weights[tsrc] ){ continue; }
            vis[tsrc]=1;//优先登记

            for( auto [b,dstw] : adjs[tsrc] ){
                if( vis[b]==1 ){ continue; }
                weights[b] = std::max( weights[b], tw*dstw );
                minHeap.push( HE{ b, weights[b] } );
            }
        }
        if( weights[end]==-9.9 ){ return 0.0; }// 不连通
        return weights[end];


    }
};




//=========================================================//
void main_(){


 
    

    debug::log( "\n~~~~ leet: 1514 :end ~~~~\n" );
}
}//~
