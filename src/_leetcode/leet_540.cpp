/*
 * ====================== leet_540.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.07
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 540. 有序数组中的单一元素
 */
#include "innLeet.h"


namespace leet_540 {//~


// 时间 O(log(n)), 空间 O(1)

// 必须使用 二分查找，不停地收缩 收缩区间

//    89%，  33%
class S{
public:
    int singleNonDuplicate( std::vector<int>& nums ){


        int l = 0;
        int r = static_cast<int>(nums.size())-1;

        while( l<=r ){
            if( l==r ){ return nums[l]; }
            int mid = l+(r-l)/2;//mid-left
            if( (mid&1)==1 ){// 奇数
                if( nums[mid-1]==nums[mid] ){
                    l = mid+1;// 检查 后区间
                }else{
                    r = mid-1;// 检查 前区间
                }
            }else{// 偶数
                if( nums[mid]==nums[mid+1] ){
                    l = mid+2; // 检查 后区间
                }else{
                    r = mid;  // 检查 前区间
                }
            }
        }
        return -999; // never reach
        

    }
};



//=========================================================//
void main_(){

    std::vector<int> v { 4,4,5,5,6,6,7 };

    auto ret = S{}.singleNonDuplicate(v);

    cout<<"ret:"<<ret<<endl;

    


    debug::log( "\n~~~~ leet: 540 :end ~~~~\n" );
}
}//~
