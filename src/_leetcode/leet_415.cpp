/*
 * ====================== leet_415.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 415. 字符串相加
 */
#include "innLeet.h"



namespace leet_415 {//~


class S{
public:

    std::string addStrings( std::string num1, std::string num2 ){

        std::deque<char> que {};

        int len1 = static_cast<int>(num1.size()); 
        int len2 = static_cast<int>(num2.size());
        int a = len1-1;
        int b = len2-1;
        int isCarry = 0;
        std::string out {};

        while( a>=0 || b>=0 ){
            int aVal = (a>=0) ? (num1.at(a)-'0') : 0;
            int bVal = (b>=0) ? (num2.at(b)-'0') : 0;
            int sum = aVal + bVal + isCarry;
            isCarry = (sum>9) ? 1 : 0;
            que.push_front( static_cast<char>('0'+sum%10) );
            a--;
            b--;
        }
        if( isCarry == 1 ){ que.push_front( '1' ); }
        //---
        while( !que.empty() ){
            out += que.front();
            que.pop_front(); 
        }
        return out;
    }

};





//=========================================================//
void main_(){

    auto ret = S{}.addStrings( "1999", "1" );

    cout << "ret = " << ret << endl;

    

    debug::log( "\n~~~~ leet: 415 :end ~~~~\n" );
}
}//~

