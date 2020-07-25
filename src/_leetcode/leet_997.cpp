/*
 * ====================== leet_997.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 997. 找到小镇的法官
 */
#include "innLeet.h"



namespace leet_997 {//~


// 本质上是道 有向图 的题
// 用 拓扑排序 topo

// 问题可被理解为：检测是否仅存在一个，出度为0 的元素，且它的 入度==N-1


//   45%,  16%
class S2{
public:
    // 1 <= N <= 1000
    // trust.length <= 10000
    // trust[i] 是完全不同的
    // trust[i][0] != trust[i][1]
    // 1 <= trust[i][0], trust[i][1] <= N
    int findJudge(int N, std::vector<std::vector<int>>& trust ){


        std::vector<int> indegrees  (N, 0);
        std::vector<int> outdegrees (N, 0);
        for( auto &e : trust ){
            outdegrees[e[0]-1]++;
            indegrees[e[1]-1]++;
        }
        int count = 0;
        int tgtIdx = 0;
        for( int i=0; i<N; i++ ){
            if( outdegrees[i]==0 ){
                tgtIdx = i;
                count++;
            }
        }
        if( count!=1 || indegrees[tgtIdx]!=N-1 ){ return -1; }
        return tgtIdx+1;

    }
};









// 5.12%, 16.67%
int findJudge( int N, std::vector<std::vector<int>>& trust ){

    if( N<=1 ){ return trust.empty() ? 1 : -1; }

    std::set<int> notSet {}; // 不是法官的名单
    std::map<int,int> candidates {}; // 法官候选人 <id, num>

    // 收集数据
    for( const auto &v : trust ){
        notSet.insert( v.at(0) );// maybe
        auto [it,bl] = candidates.emplace( v.at(1), 1 ); // maybe
        if( !bl ){ it->second++; }
    }

    // 过滤掉不可能是法官的：法官自己不信任别人
    auto it = candidates.begin();
    while( it != candidates.end() ){
        if( it->second!=N-1 || notSet.find(it->first)!=notSet.end() ){
            it = candidates.erase(it);
        }else{
            it++;
        }
    }

    if( candidates.size()==1 ){
        return candidates.begin()->first;
    }else{
        return -1;
    } 
}






//=========================================================//
void main_(){

    
    std::vector<std::vector<int>> v {
        
    };


    auto ret = findJudge( 1, v );
    cout << "ret = " << ret << endl;
    
    

    debug::log( "\n~~~~ leet: 997 :end ~~~~\n" );
}
}//~

