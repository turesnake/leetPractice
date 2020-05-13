/*
 * ====================== leet_m01_06.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 01.06. 字符串压缩
 */
#include "innLeet.h"


namespace leet_m01_06 {//~



std::string compressString( std::string S ) {

    if( S.size()<=2 ){ return S; }
    std::vector<std::pair<char,int>> cs {};
    auto it = S.begin();
    cs.emplace_back( *it, 1 );
    it++;
    for( ; it!=S.end(); it++ ){
        char newC = *it;
        if(newC == cs.back().first){
            cs.back().second++;
        }else{        
            cs.emplace_back( newC, 1 );
        }
    }

    if( cs.size()*2 >= S.size() ){ return S; }
    std::string out {};
    for( auto [c,num] : cs ){
        out += c;
        out += std::to_string(num);
    }
    return out;
}






//=========================================================//
void main_(){

    auto ret = compressString( "abbccd" );

    cout << "ret = " << ret << endl; 


    debug::log( "\n~~~~ leet: m01_06 :end ~~~~\n" );
}
}//~
