/*
 * ====================== leet_520.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.24
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 520. 检测大写字母
 */
#include "innLeet.h"


namespace leet_520 {//~



bool detectCapitalUse( std::string word ){

    int N = static_cast<int>(word.size());
    if( N==1 ){ return true; }
    // 往下一定包含 2或更多 字母
    // 小写字母开头
    if( word.at(0)>='a' && word.at(0)<='z' ){
        // 全小写
        for( char c : word ){
            if( !(c>='a' && c<='z') ){ return false; }
        }
        return true;
    }
    // 大写字母开头
    if( word.at(1)>='a' && word.at(1)<='z' ){
        for( int i=1; i<N; i++ ){
            if( !(word.at(i)>='a' && word.at(i)<='z') ){ return false; }
        }
        return true;
    }else{
        // 全大写
        for( char c : word ){
            if( !(c>='A' && c<='Z') ){ return false; }
        }
        return true;
    }
}



//=========================================================//
void main_(){

    std::vector<std::string> v {
        "a", "H", "awedwe", "sdwdasKds", "Ksadwdw", "KoooG", "KJUGT", "KJHUpG"
    };
    
    for( auto &s : v ){
        cout << s << " : " << detectCapitalUse(s) << endl;
    }


    debug::log( "\n~~~~ leet: 520 :end ~~~~\n" );
}
}//~
