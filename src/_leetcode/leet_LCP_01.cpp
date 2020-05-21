/*
 * ====================== leet_LCP_01.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * LCP 01. 猜数字
 */
#include "innLeet.h"


namespace leet_LCP_01 {//~



int game( std::vector<int>& guess, std::vector<int>& answer ){
    int sum {0};
    for( int i=0; i<3; i++ ){
        if( guess.at(i)==answer.at(i) ){ sum++; }
    }
    return sum;
}




//=========================================================//
void main_(){

    std::vector<int> v1 { 1,2,3 };
    std::vector<int> v2 { 1,2,3 };

    cout << game(v1,v2) << endl;

    
    

    debug::log( "\n~~~~ leet: LCP_01 :end ~~~~\n" );
}
}//~
