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

