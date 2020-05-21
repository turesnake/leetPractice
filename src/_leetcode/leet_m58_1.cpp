/*
 * ====================== leet_m58_1.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题58 - I. 翻转单词顺序
 * 和 151 题相同 
 */
#include "innLeet.h"


namespace leet_m58_1 {//~



std::string reverseWords( std::string s ){

    if( s.empty() ){ return s; }

    std::stack<std::string> strs {};
    bool isLstLetter {false};

    for( const char c : s ){
        bool isNowLetter = c!=' ';
        if( isNowLetter ){ // 此字
            if( isLstLetter ){// 上字
                strs.top() += c;
            }else{//上空
                strs.push( std::string {c} ); // new word
            }
        }
        isLstLetter = isNowLetter;
    }
    if( strs.empty() ){ return ""; }
    //---
    std::string out {};
    while( !strs.empty() ){
        out += strs.top();
        out += ' ';
        strs.pop();
    }
    out.pop_back();
    return out;
}



//=========================================================//
void main_(){

    cout <<"[" << reverseWords( " k   " ) << "]" << endl;

    
    

    debug::log( "\n~~~~ leet: m58_1 :end ~~~~\n" );
}
}//~
