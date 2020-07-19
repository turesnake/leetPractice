/*
 * ====================== leet_m10_03.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.19
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 10.03. 搜索旋转数组
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m10_03 {//~


// 二分查找
// 可能存在重复元素  {3,3,1,3}
// 或者:           {1,1,2,1}


// 允许重复元素 + 数组被旋转过
// 往往意味着，头部 和 尾部元素，可能是相同的
// 最推荐的做法，就是一上来，就把所有 尾部 同值元素，统统剔除掉


class S{
public:
    // arr 长度范围在[1, 1000000]之间
    // 找不到就返回 -1
    int search( std::vector<int>& arr, int target ){


        int N = static_cast<int>(arr.size());
        //=== 删除 所有和 头元素同值的 尾部元素 ===//
        for(; N>1 && arr[0]==arr[N-1]; N-- ){}
        if( N==1 ){ return arr[0]==target ? 0 : -1; }// 若数组全元素相同

        //=== 1 查找最小元素 ===//
        int l=0;
        int r=N-1;
        int mminIdx = 0;
        if( arr[l]>arr[r] ){// 确实存在 割裂
            while( l<r ){
                int mid=l+(r-l)/2;//mid-left
                if( arr[mid]>arr[r] ){
                    l = mid+1; //剔除
                }else{// arr[mid] <= arr[r]
                    r = mid;// 保留到下一回合
                }
            }
            mminIdx = l;
        }

        //=== 确定 tgt 在哪个区间 ===//
        if( target>=arr[mminIdx] && target<=arr[N-1] ){// right
            l = mminIdx;
            r = N-1;
        }else{// left
            l = 0;
            r = mminIdx-1;
        }
        //=== 正式 查找 最左侧 tgt ===//
        while( l<r ){
            int mid = l+(r-l)/2;//mid-left
            if( arr[mid] < target ){
                l = mid+1;// 坚决剔除
            }else{
                r=mid;// 保留到 下一回合
            }
        }
        return arr[l]==target ? l : -1;


    }
};




//=========================================================//
void main_(){

    std::vector<int> v { 5,5,5,1,2,3,4,5 };

    auto ret = S{}.search( v, 5 );
    cout<<"ret:"<<ret<<endl;



    debug::log( "\n~~~~ leet: m10_03 :end ~~~~\n" );
}
}//~
