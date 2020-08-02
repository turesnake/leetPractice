/*
 * ====================== leet_743.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 743. 网络延迟时间
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_743 {//~


// 最短路径算法 Dijkstra

// dijkstra 的核心就是，每一回合，都从 候选元素中，找出 临时权重值 最小的那个元素，将它确立为 已访问元素。
// 为什么这个操作 是成立的呢？？？
// 假设 在第一回合中，从起点出发，可以到达三个候选点，其中有个点a，它的 weight 最小，
// 那么我们可以肯定，这个 a 现在的 weight，就是 s->a 的最优解。
// 剩余的潜在路线（尚未完全查明的）都要从其它 w更大的路线，继续行走而来，它们一定不可能比 当前的 a.w 值更短
// 之所以这个现象成立，其实也依赖于，图中所有权重，都非负数 这个条件。
// ----
// 通过每一回合，确定一个点 的方式，最终就能逐个确定所有 点
// 这个思维多少带有 dp 的味道


//    92%    50%
class S{

struct Elem{
    int dst {};
    int w {};
};

struct PElem{
    int node {};
    int w {};
};
struct PGreater{
    bool operator()( const PElem &a, const PElem &b )const noexcept{
        return a.w > b.w;
    }
};

public:
    // 有 N 个网络节点，标记为 1 到 N
    // N 的范围在 [1, 100] 之间。
    // K 的范围在 [1, N] 之间。
    // times 的长度在 [1, 6000] 之间。
    // 所有的边 times[i] = (u, v, w) 都有 1 <= u, v <= N 且 0 <= w <= 100。
    int networkDelayTime( std::vector<std::vector<int>>& times, int N, int K) {

        std::vector<int> weights (N+1, INT_MAX);
        std::vector<char> vis (N+1, 0);
        weights[0]=0;// 空置
        weights[K]=0;

        std::vector<std::vector<Elem>> nexts (N+1, std::vector<Elem>{});
        for( auto &e : times ){
            nexts[e[0]].push_back( Elem{e[1],e[2]} );
        }

        std::priority_queue<PElem,std::vector<PElem>,PGreater> minheap {};
        minheap.push( PElem{K,0} );

        while( !minheap.empty() ){
            auto [psrc,pw] = minheap.top();
            minheap.pop();
            //--- 针对此数据，做检测，可能是过期失效的 ---//
            if( vis[psrc]==1 || weights[psrc]!=pw ){ continue; }
            //--- 正式处理 ---//
            vis[psrc] = 1;

            for( auto &nxt : nexts[psrc] ){// nexts
                if( vis[nxt.dst]==1 ){ continue; }
                int nxtW = pw+nxt.w;
                if( nxtW < weights[nxt.dst] ){
                    weights[nxt.dst] = nxtW;
                    minheap.push( PElem{nxt.dst,nxtW} );
                }
            }
        }
        //---//
        int ans = 0;
        for( int w : weights ){
            //cout<<"w:"<<w<<endl;
            if( w==INT_MAX ){ return -1; }
            ans = std::max(ans, w);
        }
        return ans;


    }
};






//=========================================================//
void main_(){

    std::vector<std::vector<int>> v {
        {1,2,1},
        {2,3,7},
        {1,3,4},
        {2,1,2}
    };

    auto ret = S{}.networkDelayTime( v, 3, 2 );
    cout<<"ret:"<<ret<<endl;


    debug::log( "\n~~~~ leet: 743 :end ~~~~\n" );
}
}//~
