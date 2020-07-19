/*
 * ====================== leet_j11.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 剑指 Offer 11. 旋转数组的最小数字
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_j11 {//~


// 二分查找

// 很特殊 很阴的 题！！！


// 存在缺陷： 
//  {3,3,3,3,1,3}
//  { 1,1,1,1,1,2,1,1,1 }

// 允许重复元素 + 数组被旋转过
// 往往意味着，头部 和 尾部元素，可能是相同的
// 最推荐的做法，就是一上来，就把所有 尾部 同值元素，统统剔除掉



//   94%   100%
class S{
public:
    // 元素是存在重复的 
    int minArray( std::vector<int>& numbers ){

        int N = static_cast<int>(numbers.size());
        for(; N>1 && numbers[0]==numbers[N-1]; N-- ){}// 剔除所有与 n[0] 同值的 尾元素

        int l=0;
        int r=N-1;
        while( l<r ){
            int mid = l+(r-l)/2;//mid-left
            if( numbers[mid] > numbers[r] ){
                l = mid+1;// 坚决剔除
            }else{// <=
                r = mid;  // 保留到下一回合
            }
        }
        return numbers[l];

    }
};



//=========================================================//
void main_(){



    debug::log( "\n~~~~ leet: j11 :end ~~~~\n" );
}
}//~
