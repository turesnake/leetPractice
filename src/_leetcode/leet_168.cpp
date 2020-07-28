/*
 * ====================== leet_168.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.27
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 168. Excel表列名称
 */
#include "innLeet.h"


namespace leet_168 {//~

// 这题容易翻车...

// 100%  100%
class S{
public:
    // n 为 正整数
    std::string convertToTitle( int n ){

        std::deque<char> que {};
        for(; n>0; n=(n-1)/26 ){
            que.push_front( 'A'+(n-1)%26 );
        }
        return std::string ( que.begin(), que.end() );

    }
};


//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 168 :end ~~~~\n" );
}
}//~
