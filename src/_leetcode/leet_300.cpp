/*
 * ====================== leet_300.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 300. 最长上升子序列 难
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_300 {//~


 
// 暴力法，逐个遍历 耗时N^2
// 目前这个方法是 错的
int lengthOfLIS_1( std::vector<int>& nums ) {

    if( nums.empty() ){ return 0; }
    if( nums.size()==1 ){ return 1; }

    int maxLen {1};
    int numsSize = static_cast<int>(nums.size());
    for( int j=0; j<numsSize; j++ ){
        int curentVal = nums.at(j);
        int len = 1;
        for( int i=j; i<numsSize; i++ ){
            if( nums.at(i) > curentVal ){
                curentVal = nums.at(i);
                len++;
            }
        }
        maxLen = std::max( maxLen, len );
    }
    return maxLen;
}


// 暴力法
// 老实地罗列 所有可行的 递增队列
int lengthOfLIS_3( std::vector<int>& nums ) {

    if( nums.empty() ){ return 0; }
    if( nums.size()==1 ){ return 1; }

    std::stack<int> stk {};
    std::vector<std::vector<int>> stks ( 1, std::vector<int>{} );// 默认存在一个 空栈
    stks.back().push_back( nums.at(0) ); // 先压入首元素

    int curentVal {0};
    int lastVal   { nums.at(0) };

    for( int j=1; j<static_cast<int>(nums.size()); j++ ){ // 首元素已被处理
        curentVal = nums.at(j);

        if( curentVal >= lastVal ){ // 上升
            // 将新元素，添加到所有能添加的 队伍的尾部
            for( auto &stkRef : stks ){
                if( curentVal > stkRef.back() ){
                    stkRef.push_back( curentVal );
                }
            }
        }else{ // 下降
            int maxDeep {0};//插入位置,指向队列中，>= currentVal 的元素
            int maxDeepStkIdx {};

            for( int idx=0; idx<static_cast<int>(stks.size()); idx++ ){
                auto &stkRef = stks.at(idx);
                
                for( int i=0; i<static_cast<int>(stkRef.size()); i++ ){
                    if( (stkRef.at(i) >= curentVal) && (i >= maxDeep) ){
                        // 找到更长的 可插入队列
                        maxDeep = i;
                        maxDeepStkIdx = idx;
                        break;
                    }
                }   
            }
            // 添加新队列
            stks.push_back( std::vector<int>{} );
            auto &targetStk = stks.at( maxDeepStkIdx );
            // 将目标队列 前某段数据，复制给 新队列
            for( int i=0; i<maxDeep; i++ ){
                stks.back().push_back( targetStk.at(i) );
            }
            stks.back().push_back( curentVal ); // 全新元素
        }
        lastVal = curentVal;
    }

    size_t maxLen {1};
    for( const auto &c : stks ){
        maxLen = std::max( maxLen, c.size() );
    }
    return static_cast<int>(maxLen);
}








//=========================================================//
void main_(){

    std::vector<int> v { 4,10,4,3,8,9 };
    
    int ret = lengthOfLIS_3( v );

    cout << "ret = " << ret << endl;


    debug::log( "\n~~~~ leet: 300 :end ~~~~\n" );
}
}//~

