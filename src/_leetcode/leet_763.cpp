/*
 * ====================== leet_763.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 划分字母区间
 */
#include "innLeet.h"


namespace leet_763 {//~



std::vector<int> partitionLabels( std::string S ) {

    std::vector<int> out {};
    if( S.empty() ){ return out; }
    if( S.size()==1 ){
        out.push_back(1);
        return out;
    }

    std::vector<std::pair<int,int>> ranges ( 26, std::pair<int,int>{999,-1} ); // <minIdx,maxIdx>

    int aIdx = static_cast<int>('a');
    for( int i=0; i<static_cast<int>(S.size()); i++ ){
        int idx = static_cast<int>(S.at(i)) - aIdx;
        ranges.at(idx).first = std::min( ranges.at(idx).first, i );
        ranges.at(idx).second = std::max( ranges.at(idx).second, i );
    }

    // delete elems
    auto it = ranges.begin();
    while( it != ranges.end() ){
        ( it->first==999 ) ?
                it = ranges.erase(it) :
                it++;
    }

    // sort
    std::sort( ranges.begin(), ranges.end() );

    // range combine
    it = ranges.begin();
    std::vector<std::pair<int,int>> r2 { *it };
    while ( it != ranges.end() ){
        if( it->first > r2.back().second ){ // 相离
            r2.push_back( *it );
        }else{ // 相交，相邻
            r2.back().second = std::max( r2.back().second, it->second );
        }
        it++;
    }

    // get lens
    for( const auto &ip : r2 ){
        out.push_back( ip.second - ip.first + 1 );
    }
    
    return out;
}





//=========================================================//
void main_(){

    //auto ret = partitionLabels( "dehijhklijababcbacadefeg" );
    //auto ret = partitionLabels( "ababcbacadefegdehijhklij" );
    auto ret = partitionLabels( "f" );


    for( const auto i : ret ){
        cout << i << ", ";
    }
    cout << endl;
    


    debug::log( "\n~~~~ leet: 763 :end ~~~~\n" );
}
}//~
