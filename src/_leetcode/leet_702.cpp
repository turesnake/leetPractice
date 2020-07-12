/*
 * ====================== leet_702.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 702. 搜索长度未知的有序数组
 */
#include "innLeet.h"


namespace leet_702 {//~


// 两次 二分查找
// 先找出 数组 右边界
// 再在 数据区间内，查找 目标值


// 此题 有个 隐藏的 技巧：
// 目标数组 取值范围是 [-9999,9999],且元素 各不相同
// 意味着，数组 个数 一定不超过 20000


// interface
// 如果 index 越界，返回 2147483647
class ArrayReader {
public:
    int get(int index);
};



//   66%   100%
class S{
public:
    // 数组元素 互不相同
    // -9999 <= [i] <= 9999
    int search( ArrayReader& reader, int target) {

        // find right bound
        int l=0;
        int r=20000;//  优化点！！！！！！！！
        while( l<=r ){
            if( l==r ){
                if( reader.get(l)==INT_MAX ){ return -1; }// 区间内 唯一的值 也不符合
                break;
            }
            int mid = l+(r-l)/2+1;//mid-right
            if( reader.get(mid)==INT_MAX ){
                r = mid-1;// 坚决剔除
            }else{
                l = mid;// 保留到下一回合
            }
        }
        //=== 重新调整 l/r, 指向数组区间，进行二次查找 ===//
        l=0;
        while( l<=r ){
            if( l==r ){
                return reader.get(l)==target ? l : -1;
            }
            int mid = l+(r-l)/2;//mid-left
            int midVal = reader.get(mid);
            if( midVal<target  ){
                l = mid+1;
            }else if( midVal>target ){
                r = mid-1;
            }else{
                return mid;
            }
        }
        return -1;
        
    }
};





//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 702 :end ~~~~\n" );
}
}//~
