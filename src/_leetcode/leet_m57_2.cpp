/*
 * ====================== leet_m57_2.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题57 - II. 和为s的连续正数序列
 */
#include "innLeet.h"


namespace leet_m57_2 {//~


// 暴力法
// 居然 47.41%, 100% 
// 先不管了
std::vector<std::vector<int>> findContinuousSequence_0( int target ){

    std::vector<std::vector<int>> outs {};
    for( int idx=1; idx<=target/2; idx++ ){
        bool isFind {false};
        int sum = 0;
        int r=idx;
        for( ; r<=target; r++ ){
            sum += r;
            if( sum == target ){
                isFind = true;
                break;
            }else if( sum > target ){
                break;
            }
        }
        if( isFind ){
            outs.push_back( {} );
            for( int i=idx; i<=r; i++ ){
                outs.back().push_back( i );
            }
        }
    }
    return outs; 
}




//=========================================================//
void main_(){

    auto ret = findContinuousSequence_0( 36 );

    for( const auto &c : ret ){
        for( int i : c ){
            cout << i << ", ";
        }
        cout << endl;
    }
    


    debug::log( "\n~~~~ leet: m57_2 :end ~~~~\n" );
}
}//~
