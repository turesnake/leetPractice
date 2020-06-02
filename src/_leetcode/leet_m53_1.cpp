/*
 * ====================== leet_m53_1.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题53 - I. 在排序数组中查找数字 I
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_m53_1 {//~


// 46%, 100%
// 一点小优化： 在第一遍搜索后，可以获得一个，容纳目标数的 更小的区间
class S{
public:
    int search( std::vector<int> nums, int target ){

        if( nums.empty() ){ return 0; }

        int N = static_cast<int>(nums.size());
        //--- find fst one ---//
        int l=0;
        int r=N-1;
        int fstIdx {};
        bool isFind {false};
        while( l<=r ){
            fstIdx = l+(r-l)/2;//mid-left
            int v = nums.at(fstIdx);
            if( target < v ){
                r = fstIdx-1;
            }else if( target > v ){
                l = fstIdx+1;
            }else{
                isFind = true;
                break;// find
            }
        }
        if( !isFind ){ return 0; } // not find

        // 第一次查找中，可以获得一个 更小的搜索区间
        int outL = l;
        int outR = r;

        //--- find left ---//
        int lIdx {};// 目标值区间左下标
        int rIdx {};// 目标值区间右下标
        l = outL;
        r = fstIdx;
        while( l<=r ){
            if( l==r ){ lIdx = l; break; }
            int mid = l+(r-l)/2;//mid-left
            if( nums.at(mid) < target ){
                l = mid+1;// 坚决剔除
            }else{
                r = mid;// 保留到下一回合
            }
        }
        //--- find right ---//
        l = fstIdx;
        r = outR;
        while( l<=r ){
            if( l==r ){ rIdx = l; break; }
            int mid = l+(r-l)/2+1;//mid-right
            if( nums.at(mid) > target ){
                r = mid-1; // 坚决剔除
            }else{
                l = mid;// 保留到下一回合
            }
        }
        return rIdx-lIdx+1;
    }
};







//=========================================================//
void main_(){

    cout << S{}.search( {1,2,2,3,4,5,6,7,8,9,10,11,12,13}, 2 ) <<endl;

    
    

    debug::log( "\n~~~~ leet: m53_1 :end ~~~~\n" );
}
}//~
