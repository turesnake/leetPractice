/*
 * ====================== leet_128.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 128. 最长连续序列
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_128 {//~



// 一种特殊的 并查集  89%， 6%

// 最优解法是使用 uset：
// 任取一个值，探索其左边界 和 右边界
// 将探索过的 元素全部删除，节省未来的 查找时间

class S{
public:
    int longestConsecutive( std::vector<int>& nums ){

        if( nums.empty() ){ return 0; }
        std::unordered_set<int> uset {};
        for( int i : nums ){
            uset.insert(i);
        }
        int mmax = -1;

        for( int num : nums ){
            if( uset.count(num)==0 ){ continue; }

            int l=num;
            while( uset.count(l)>0 ){
                uset.erase(l);
                l--;
            }// l 出界了
            l++;// l 指向区间左元素

            int r=num+1;
            while( uset.count(r)>0 ){
                uset.erase(r);
                r++;
            }// r 出界了
            r--;// r 指向区间右元素

            mmax = std::max(mmax, r-l+1);
        }
        return mmax;
    }
};




//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 128 :end ~~~~\n" );
}
}//~
