/*
 * ====================== leet_13.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 13. 罗马数字转整数
 */
#include "innLeet.h"


namespace leet_13 {//~


// 39.86%, 100%
class S {
    std::unordered_map<char, int> mp {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 }
    };

public:

    int romanToInt( std::string s ){
        int sSize = static_cast<int>(s.size());
        int sum {0};

        for( int i=0; i<sSize; i++ ){
            char currentC = s.at(i);
            bool isDouble {false};

            if( i+1<sSize ){// 后一位存在值
                char nextC = s.at(i+1);
                if( currentC == 'I' ){
                    switch(nextC){
                        case 'V': isDouble=true; sum += 4; break; 
                        case 'X': isDouble=true; sum += 9; break; 
                        default: break; // do nothing
                    }
                }else if( currentC == 'X' ){
                    switch(nextC){
                        case 'L': isDouble=true; sum += 40; break; 
                        case 'C': isDouble=true; sum += 90; break; 
                        default: break; // do nothing
                    }
                }else if( currentC == 'C' ){
                    switch(nextC){
                        case 'D': isDouble=true; sum += 400; break; 
                        case 'M': isDouble=true; sum += 900; break; 
                        default: break; // do nothing
                    }
                }
            }
            if( isDouble ){
                i++; // 额外++
                continue;
            }
            sum += mp.at( currentC );
        }
        return sum;    
    }


};




//=========================================================//
void main_(){

    S obj {};

    for( std::string s : { "III", "IV", "IX", "LVIII", "MCMXCIV" } ){

        debug::log( "s:{}, ret: {}", s, obj.romanToInt(s) );
    }
    
    


    debug::log( "\n~~~~ leet: 13 :end ~~~~\n" );
}
}//~
