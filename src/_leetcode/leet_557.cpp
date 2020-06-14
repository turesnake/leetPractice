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


// 写得有点乱 

// 69%  100%
std::string reverseWords( std::string s ){

    if( s.empty() ){ return s; }

    int N = static_cast<int>(s.size());
    int l = 0;
    int r = 0;
    for( ; l<N && s.at(l)==' '; l++ ){}
    if( l==N ){ return ""; }// 此单词只有一串 空格
    // 现在，l指向第一个有效字符
    int f = l;

    while( l<N && r<N ){
        for( ; f<N && s.at(f)!=' '; f++ ){}// f 找到单词后第一个空格
        r = f-1;
        for( ; l<r; l++,r-- ){
            std::swap( s.at(l), s.at(r) );
        }
        f++;
        l = f;
    }
    return s;
}






//=========================================================//
void main_(){

    for( std::string &s : std::vector<std::string>{ " abcd abc 123 1 " } ){
        cout << s << " : " << "[" << reverseWords(s) << "]" << endl; 

    }
    



    debug::log( "\n~~~~ leet: 557 :end ~~~~\n" );
}
}//~
