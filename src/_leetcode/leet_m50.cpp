/*
 * ====================== leet_m50.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题50. 第一个只出现一次的字符
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m50 {//~



char firstUniqChar( std::string s ){
    // -1: 暂未登记过
    // -2: 重复元素
    // >=0 第一次找到时的下标
    std::vector<int> vs ( 26, -1 );// 'a'-'z'

    int N = static_cast<int>(s.size());
    for( int i=0; i<N; i++ ){
        int idx = static_cast<int>(s.at(i)-'a');
        int val = vs.at(idx);
        if( val == -1 ){// 暂未登记
            vs.at(idx) = i;
        }else if( val != -2 ){
            vs.at(idx) = -2;
        }
    }
    int minIdx {INT_MAX};
    char c {};
    for( int i=0; i<26; i++ ){
        int val = vs.at(i);
        if( val>=0 && val<minIdx ){
            minIdx = val;
            c = 'a'+i;
        }
    }
    return (minIdx==INT_MAX) ? ' ' : c;
}





//=========================================================//
void main_(){

  

    debug::log( "[{}]", firstUniqChar( "" ) );
    

    

    debug::log( "\n~~~~ leet: m50 :end ~~~~\n" );
}
}//~
