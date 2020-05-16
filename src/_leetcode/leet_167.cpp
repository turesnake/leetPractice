/*
 * ====================== leet_167.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 167. 两数之和 II - 输入有序数组
 */
#include "innLeet.h"


namespace leet_167 {//~


// set 搜索法 16%, 6.9%
// 看来是 排进 set 本身消耗了过多时间
std::vector<int> twoSum( std::vector<int>& numbers, int target ){

    std::vector<int> outs {};
    std::unordered_set<int> sett ( numbers.begin(), numbers.end() );
    int numsSize = static_cast<int>(numbers.size());
    int aIdx {};// base on 0
    int bIdx {};// base on 0
    int bVal {};
    // 寻找目标匹配对
    for( int i=0; i<numsSize; i++ ){
        int v = numbers.at(i);
        if( sett.find(target-v) != sett.end() ){ // 找到匹配对
            aIdx = i;
            bVal = target-v;
            break;
        }
    }
    // find bIdx
    for( int i=aIdx+1; i<numsSize; i++ ){
        if( numbers.at(i) == bVal ){
            bIdx = i;
            break;
        }
    }
    outs.push_back( aIdx+1 );
    outs.push_back( bIdx+1 );
    return outs;
}



// 双指针法. 从头部和尾部，相向而行
std::vector<int> twoSum_2( std::vector<int>& numbers, int target ){

    if( numbers.size()==2 ){ return {1,2}; } // 题目保证一定有解了...

    int numsSize = static_cast<int>(numbers.size());
    int left = 0;
    int right = numsSize-1;
    while( left < right ){
        int sum = numbers.at(left) + numbers.at(right);
        if( sum == target ){
            return { left+1, right+1 };
        }else if( sum > target ){
            right--;
        }else{
            left++;
        }
    }
    return {}; //  never reach
}





//=========================================================//
void main_(){


    std::vector<int> v { 1,3,5,7 };
    auto ret = twoSum_2( v, 8 );

    for( const int i : ret ){
        cout << i << ", ";
    }
    cout << endl;

    debug::log( "\n~~~~ leet: 167 :end ~~~~\n" );
}
}//~

