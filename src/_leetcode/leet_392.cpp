/*
 * ====================== leet_392.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 392. 判断子序列
 */
#include "innLeet.h"


namespace leet_392 {//~


// 双指针即可，不能算 dp


//   88%   100%
class S{
public:
    // s.len <= 100
    // t.len <= 500,000
    bool isSubsequence( std::string s, std::string t){

        if( s.empty() ){ return true; }
        if( t.empty() ){ return false; }

        int N = static_cast<int>(t.size());
        int i = 0;
        for( char c : s ){
            for( ; i<N && t[i]!=c; i++  ){}
            if( i>=N ){ return false; }
            i++; // 跳过目标字母
        }
        return true;

    }
};



//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 392 :end ~~~~\n" );
}
}//~
