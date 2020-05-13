/*
 * ====================== leet_283.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 移除零
 */
#include "innLeet.h"


namespace leet_283 {//~



void moveZeroes( std::vector<int>& nums) {

    auto fast = nums.begin();
    auto slow = fast;

    for( ; fast<nums.end(); fast++ ){
        if( *fast != 0 ){
            *slow = *fast;
            slow++;
        }
    }

    while( slow < nums.end() ){
        *slow = 0;
        slow++;
    }
}





//=========================================================//
void main_(){

    std::vector<int> v { 3,0,1 };
    //std::vector<int> v { 0,1,2,3,4 };
    //std::vector<int> v { 0,1,0,3,12 };
    moveZeroes( v  );


    for( const auto &i : v ){
        cout << i << ", ";
    }
    cout << endl;


    debug::log( "\n~~~~ leet: 283 :end ~~~~\n" );
}
}//~
