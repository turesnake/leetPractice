/*
 * ====================== leet_260.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.07
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 260. 只出现一次的数字 III
 */
#include "innLeet.h"


namespace leet_260 {//~


// 异或 操作可以删除 偶数个的 重复值。
// 本题中，需要寻找两个单独数，核心就是两这两个 单独数 拆分到 两个 区间去做 异或 累计操作 



//   49%   6%
class S{
public:
    std::vector<int> singleNumber( std::vector<int>& nums ){

        // 全部元素 亦或累计值
        int xorSum = 0;
        for( int i : nums ){ xorSum ^= i; }

        int lowDiff = xorSum&(-xorSum); // lowbit 运算，找到 最低位的 1

        int xora = 0;
        int xorb = 0;
        for( int i : nums ){
            (i&lowDiff)==lowDiff ?
                    xora ^= i :
                    xorb ^= i;
        }
        return std::vector<int> { xora, xorb };
    }
};




//=========================================================//
void main_(){

    std::vector<int> v { 1,2,1,3,2,5 };

    auto ret = S{}.singleNumber( v );

    for( int i:ret ){
        cout<<i<<", ";
    }cout<<endl;


    debug::log( "\n~~~~ leet: 260 :end ~~~~\n" );
}
}//~
