/*
 * ====================== leet_m03.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题03. 数组中重复的数字
 */
#include "innLeet.h"


namespace leet_m03 {//~


// 暴力法
// uset 快于 set
int findRepeatNumber_1( std::vector<int>& nums ){

    std::unordered_set<int> sett {};
    for( int i : nums ){
        if( sett.erase(i)!=0 ){ return i; }
        sett.insert( i );
    }
    return 0; // never reach
}


// 暴力法
// 用 vector 存储元素，牺牲内存缩短访问时间  61.66%, 100%
int findRepeatNumber_2( std::vector<int>& nums ){

    std::vector<uint8_t> v ( nums.size(), 0 );
    for( int i : nums ){
        if( v.at(i)>0 ){ return i; }
        v.at(i)++;
    }
    return 0; // never reach
}





//=========================================================//
void main_(){

    std::vector<int> v { 2,3,1,0,2,5,3 };

    auto ret = findRepeatNumber_2( v );

    cout << "ret = " << ret << endl;



    
    


    debug::log( "\n~~~~ leet: m03 :end ~~~~\n" );
}
}//~
