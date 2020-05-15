/*
 * ====================== leet_169.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.15
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 169. 多数元素
 */
#include "innLeet.h"


namespace leet_169 {//~


// 笨笨法
int majorityElement_1( std::vector<int>& nums ){
        
    std::map<int,int> mp {}; // <val,nums>
    int halfNum = static_cast<int>(nums.size())/2;
    for( const int i : nums ){
        auto [it,bl] = mp.emplace( i, 1 ); // maybe
        if( !bl ){ it->second++;} // existed
        if( it->second > halfNum ){ // 已经满足要求了，直接返回，节省时间
            return i;
        }
    }
    return 0; // never used
}




// Boyer-Moore Algorithm 多数投票算法
// 因为目标元素数量过半，所以给它的投票票数，一定大于0
int majorityElement_2( std::vector<int>& nums ){
    // 第一遍扫描，找到数量过半的元素
    // 如果没有符合要求的元素，candidate 的值是无意义的
    int count {0};
    int candidate {};
    for( const int i : nums ){
        if( count == 0 ){ candidate = i; }
        ( candidate == i ) ?
            count++ :
            count--;
    }
    // 第二遍扫描，确认 candidate 就是目标值
    count = 0;
    for( const int i : nums ){
        if( i == candidate ){ count++; }
    }
    if( count > static_cast<int>(nums.size())/2 ){
        return candidate;
    }else{
        assert( 0 );
        return 0; // never reach
    }  
}
    // 无法通过 统计 candidate 个数的方式来 简化流程。
    // 当中途 candidate 发生切换后，原来累计的 个数，就被清零了
    // 所以为了确保，最终生成的值 是符合要求的，必须再次遍历一次，统计个数









//=========================================================//
void main_(){

    std::vector<int> v { 2,2,1,1,1,2,2 };
    auto ret = majorityElement_2( v );
    cout << "ret = " << ret << endl;




    debug::log( "\n~~~~ leet: 169 :end ~~~~\n" );
}
}//~

