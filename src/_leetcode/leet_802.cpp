/*
 * ====================== leet_802.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 802. 找到最终的安全状态
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_802 {//~


// 拓扑排序，逐个收集 出度为0 的点
// 直到最后，剩下一个集合，里面的元素，出度都大于0
// 这个集合内的元素，其实组成了一个环
// 它们都不符合 题目要求


//   13%   6%
class S{
public:
    // graph 节点数不超过 10000
    // 图的边数不会超过 32000
    // 每个 graph[i] 被排序为不同的整数列表， 在区间 [0, graph.length - 1] 中选取
    std::vector<int> eventualSafeNodes( std::vector<std::vector<int>>& graph ){

        int N = static_cast<int>(graph.size());

        std::vector<std::unordered_set<int>> fronts (N,std::unordered_set<int>{});//前缀节点
        std::vector<int> outdegrees (N,0);
        std::vector<char> vis (N,0);

        for( int i=0; i<N; i++ ){
            for( int b : graph[i] ){
                outdegrees[i]++;
                fronts[b].insert(i);
            }
        }

        std::vector<int> ans {};
        while( true ){
            bool isFindZero = false;
            for( int i=0; i<N; i++ ){
                if( outdegrees[i]==0 ){
                    isFindZero = true;
                    outdegrees[i] = -1;
                    for( int b : fronts[i] ){
                        outdegrees[b]--;
                    }
                    ans.push_back( i );
                }
            }
            if( !isFindZero ){ break; }
        }
        std::sort( ans.begin(), ans.end() );
        return ans;


    }
};



//=========================================================//
void main_(){

    

    debug::log( "\n~~~~ leet: 802 :end ~~~~\n" );
}
}//~
