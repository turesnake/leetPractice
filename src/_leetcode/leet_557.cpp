/*
 * ====================== leet_557.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.24
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 557. 反转字符串中的单词 III
 */
#include "innLeet.h"


namespace leet_557 {//~




std::string reverseWords( std::string s ){

    if( s.empty() ){ return s; }

    int N = static_cast<int>(s.size());

    int l = 0;
    int r = 0;

    for( ; l<N && s.at(l)==' '; l++ ){}
    if( l==N ){ return ""; }// 此单词只有一串 空格
    // 现在，l指向第一个有效字符


    // 未来做...




    
    return "kkk";
}






//=========================================================//
void main_(){

    for( std::string &s : std::vector<std::string>{ "   " } ){
        cout << s << " : " << "[" << reverseWords(s) << "]" << endl; 

    }
    



    debug::log( "\n~~~~ leet: 557 :end ~~~~\n" );
}
}//~
