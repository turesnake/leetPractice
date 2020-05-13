/*
 * ====================== leet_451.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 根据字符出现频率排序
 */
#include "innLeet.h"


namespace leet_451 {//~



std::string frequencySort( std::string s ){

    if( s.size() <= 1 ){ return s; }

    std::unordered_map<char,int> mp {};
    for( char c : s ){
        auto [insertIt, insertBool] = mp.emplace(c, 1);
        if( !insertBool ){
            insertIt->second++;
        }
    }

    std::priority_queue<std::pair<int,char>> heap {};
    for( const auto [c,num] : mp ){
        heap.emplace( num, c );
    }

    std::string out {};
    while( !heap.empty() ){
        out.insert( out.end(), heap.top().first, heap.top().second );
        heap.pop();
    }
    return out;
}




//=========================================================//
void main_(){

    auto ret = frequencySort( "" );

    cout << ret << endl;
    



    debug::log( "\n~~~~ leet: 451 :end ~~~~\n" );
}
}//~
