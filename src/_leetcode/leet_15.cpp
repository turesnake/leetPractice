/*
 * ====================== leet_15.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 15. 三数之和
 */
#include "innLeet.h"


namespace leet_15 {//~



// 这题甚至比很多困难题都麻烦 ...


// 最稳定的思路就是：
// -1- 数组排序，
// -2- 用 a 遍历整个数组，
// -3- 用头尾双指针 b,c 遍历 a之后的区间，查找 匹配组合
// a,b,c 都要去重
// ---
// 优化点： 当 [a]>0, 意味着 后面元素都大于0，可以直接终止 检测

// 时间 O(N^2)



// 2020_0727   55%   7%
// -----
// 目前为止，最精简的版本，核心在于去重
// 使用 if 来去重，易于理解，性能也不亏。
// 从 重复区 的第二个元素开始去，这种实现，能覆盖一些极限情况，比如 [b]==[c] 时，
// 不会因为 b 的去重，将 这个可能性删除掉
class S5{
public:
    std::vector<std::vector<int>> threeSum( std::vector<int>& nums ){

        int N = static_cast<int>(nums.size());
        if(N<3){ return {}; }
        std::vector<std::vector<int>> outs {};
        std::sort( nums.begin(), nums.end() );

        for(int a=0; a<N-2; a++ ){
            if( nums[a]>0 ){ break; }// 优化点
            if( a>0 && nums[a]==nums[a-1] ){ continue; }//去重

            int b=a+1;
            int c=N-1;
            while( b<c ){
                if( b>a+1 && nums[b]==nums[b-1] ){ b++; continue; }//去重
                if( c<N-1 && nums[c]==nums[c+1] ){ c--; continue; }//去重

                int tsum = nums[a] + nums[b] + nums[c];
                if( tsum>0 ){
                    c--;
                }else if( tsum<0 ){
                    b++;
                }else{// ==
                    outs.push_back( { nums[a], nums[b], nums[c] } );
                    b++; 
                    c--;
                }
            }
        }
        return outs;

    }
};





//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: 15 :end ~~~~\n" );
}
}//~
