/*
 * ====================== leet_66.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.25
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 66. 加一
 */
#include "innLeet.h"


namespace leet_66 {//~



std::vector<int> plusOne( std::vector<int>& digits ){

    int N = static_cast<int>(digits.size());
    int isCarry = 0;
    for( int i=N-1; i>=0; i-- ){
        int sum = digits.at(i) + isCarry + ((i==N-1)?1:0);
        isCarry = (sum>9) ? 1 : 0;
        digits.at(i) = sum%10;
    }
    if( isCarry ){
        std::vector<int> v { 1 };
        v.insert( v.end(), digits.begin(), digits.end() );
        return v;
    }else{
        return digits;
    }
}


//=========================================================//
void main_(){

    std::vector<int> v { 4,3,2,1 };

    cout << "{";
    for( int i : plusOne(v) ){ cout << i << ", ";}
    cout << "}" << endl;

    
    


    debug::log( "\n~~~~ leet: 66 :end ~~~~\n" );
}
}//~
