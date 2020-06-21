/*
 * ====================== leet_521.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 521. 最长特殊序列 Ⅰ
 */
#include "innLeet.h"


namespace leet_521 {//~


// 最长特殊序列 这个定义就很迷
// 如果两字符串 长度不同，那么，长的那个，一定就是 目标


// 这就是个 脑残题...


//   27%  100%
class S{
public:
    // 两个字符串长度均处于区间 [1 - 100]
    // 字符串中的字符仅含有 'a'~'z'
    int findLUSlength( std::string a, std::string b ){

        int Na = static_cast<int>(a.size());
        int Nb = static_cast<int>(b.size());
        if( Na != Nb ){
            return std::max(Na,Nb);
        }
        return a==b ? -1 : Na;
        
    }
};





//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 521 :end ~~~~\n" );
}
}//~
