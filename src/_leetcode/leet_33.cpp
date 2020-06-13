/*
 * ====================== leet_33.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.11
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 33. 搜索旋转排序数组
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_33 {//~


//  68%   100%
// 通过二分查找，找到分界线
// 然后再次用 二分查找，搜索 target
class S{
public:
    // 不存在重复元素
    // ret 目标值下标，找不到返回 -1
    int search( std::vector<int>& nums, int target ){

        if(nums.empty()){ return -1; }
        if(nums.at(0)==target){ return 0; }
        int N = static_cast<int>(nums.size());
        // 寻找最大值下标
        int big = 0;
        int l=0;
        int r=N-1;
        int tVal = nums.at(0);//待比较的值
        while( l<=r ){
            if( l==r ){ big=l; break; }
            int mid = l+((r-l)>>1)+1;//mid-right
            int v = nums.at(mid);
            if( v < tVal ){// 最大值在 左侧
                r = mid-1; // 坚决剔除
            }else{// 最大值在 右侧
                l = mid; // 保留到下一回合
                tVal = v;
            }
        }
        //cout<<"big:"<<big << ", val:"<< nums.at(big)<<endl;
        // 确认真正的搜索区间
        if( target > nums.at(0) ){
            l = 1;
            r = big;
        }else{
            l = big+1;
            r = N-1;
        }
        while( l<=r ){
            if( l==r ){ return nums.at(l)==target ? l : -1; }
            int mid = l+((r-l)>>1);
            int v = nums.at(mid);
            if( target < v ){
                r = mid-1;
            }else if( target > v ){
                l = mid+1;
            }else{// ==
                return mid;
            }
        }
        return -1;        
    }
};




//=========================================================//
void main_(){

    std::vector<int> v { 4,5,6,7,0,1 };

    cout<<"ret:"<< S{}.search(v,-44)<<endl;
    


    
    debug::log( "\n~~~~ leet: 33 :end ~~~~\n" );
}
}//~
