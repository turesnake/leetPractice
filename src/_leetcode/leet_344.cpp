/*
 * ====================== leet_344.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 344. 反转字符串
 */
#include "innLeet.h"


namespace leet_344 {//~




void reverseString( std::vector<char>& s ){

    if( s.size()<2 ){ return; }
    // 以下 字符个数 一定为 2或更多
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;
    for( ; left<right; left++,right-- ){
        std::swap( s.at(left), s.at(right) );
    }
}






//=========================================================//
void main_(){

    std::vector<char> v { 'k' };
    //std::vector<char> v { 'a', 'b', 'c', 'd' };

    reverseString( v );

    for( const char c : v ){
        cout << c << ", ";
    }
    cout << endl;
    





    debug::log( "\n~~~~ leet: 344 :end ~~~~\n" );
}
}//~
