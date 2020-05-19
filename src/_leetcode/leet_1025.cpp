/*
 * ====================== leet_1025.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1025. 除数博弈
 */
#include "innLeet.h"


namespace leet_1025 {//~


// 动态规划
// N==2,谁先手谁赢
// N==3,谁先手谁输

class S{
public:

    bool divisorGame( int N ){

        std::unordered_map<int,bool> dp {}; // <n,bool>
            // 存储 [1,N] 每个值的结果，方便快速获得答案
        std::vector<int> falses {};    
            // dp中，所有值为 true 的数，也是当b处于这个状态时，a会赢的数

        dp.emplace( 1, false );
        dp.emplace( 2, true );
        dp.emplace( 3, false );
        falses.push_back( 1 );
        falses.push_back( 3 );

        for( int n=4; n<=N; n++ ){
            bool isTrue {false};
            for( int y : falses ){
                if( n%(n-y) == 0 ){
                    isTrue = true;
                    break;
                }
            }
            if( isTrue ){
                dp.emplace( n, true );
            }else{
                dp.emplace( n, false );
                falses.push_back( n );
            }
        }
        return dp.at(N);
    }
};





//=========================================================//
void main_(){

    for( int i : { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 } ){

        debug::log( "{} - val: {}", i, S{}.divisorGame(i) );
    }

    


    debug::log( "\n~~~~ leet: 1025 :end ~~~~\n" );
}
}//~
