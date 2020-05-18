/*
 * ====================== leet_821.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 821. 字符的最短距离
 */
#include "innLeet.h"


namespace leet_821 {//~




std::vector<int> shortestToChar( std::string S, char C ){

    int ssize = static_cast<int>(S.size());

    std::vector<int> idxs { -20000 };
    // 收集所有 C 字符下标
    for( int i=0; i<ssize; i++ ){
        if( S.at(i) == C ){ idxs.push_back(i); }
    }
    idxs.push_back( 20000 ); // 左右两侧都放置了 哨兵，元素个数一定大于 2

    std::vector<int> outs {};
    int left = 0;  //遍历 idxs 用的下标，其元素值，永远小于等于 当前检测值 i
    int right = left + 1;
    for( int i=0; i<ssize; i++ ){
        int off {0};
        if( idxs.at(right) == i ){
            off = 0;
            right++;
            left++;
        }else{// 大于
            off = std::min( i-idxs.at(left), idxs.at(right)-i );
        }
        outs.push_back( off );
    }
    return outs;
}



//=========================================================//
void main_(){

    auto ret = shortestToChar( "ek", 'e' );

    cout << "ret.size = " << ret.size() << endl;
    for( int i : ret ){
        cout << i << ", ";
    }
    cout << endl;

  
    debug::log( "\n~~~~ leet: 821 :end ~~~~\n" );
}
}//~
