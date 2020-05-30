/*
 * ====================== leet_278.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 278. 第一个错误的版本
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_278 {//~

int target {4};


bool isBadVersion(int version){
    return version>=target;
}



// 二分查找
// 小于目标值的(返回 false)，一定不属于，被彻底剔除
// 大于目标值的(返回 true)， 可能属于，要保留到下次检测
int firstBadVersion(int n){//[1,n]
    int l=0;
    int r=n;
    while( l<=r ){
        if( l==r ){ return l; } // 目标值
        int mid = l+(r-l)/2;
        bool bl = isBadVersion(mid);
        if( bl ){//大于等于，可能属于，保留到下一次
            r = mid;
        }else{//小于目标值，一定不属于，被剔除
            l = mid+1;
        }
    }
    return -99; // never reach
}



//=========================================================//
void main_(){

    // 详细地排查 二分查找 


    for( int N=1; N<=33; N++ ){
        for( int i=1; i<=N; i++ ){
            target = i; tprAssert( firstBadVersion(N)==target );
        }
    }
    


    
    debug::log( "\n~~~~ leet: 278 :end ~~~~\n" );
}
}//~
