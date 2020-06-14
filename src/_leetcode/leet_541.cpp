/*
 * ====================== leet_541.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 541. 反转字符串 II
 */
#include "innLeet.h"


namespace leet_541 {//~


// 53%  100%
// 翻k个，保留k个
// 字符串小于等于 k个时，全翻 
class S{
public:
    // 1<= len <= 10000
    // 1<= k <= 10000
    std::string reverseStr( std::string s, int k ){

        int N = static_cast<int>(s.size());
        int ml = 0;
        while( true ){
            int mr = ml+k-1;
            if( mr>=N-1 ){ mr = N-1; }
            // swap
            for( int l=ml,r=mr; l<r; l++,r-- ){
                std::swap( s.at(l), s.at(r) );
            }            
            ml += 2*k;
            if( ml>=N-1 ){ return s; }
        }
        return "";//never reach
    }
};






//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 541 :end ~~~~\n" );
}
}//~
