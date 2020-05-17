/*
 * ====================== gcd.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 最大公约数
 * 参数限制为 正整数
 */
#ifndef TPR_GCD_H
#define TPR_GCD_H
#include "pch.h"

namespace tpr_gcd{//~


// 相减法 1
// 存在缺陷，效率不高
int gcd_1( int a, int b ){

    if( a == b ){ return a; }
    int nA = (a>b) ? b : a;
    int nB = (a>b) ? a-b : b-a;
    return (nA>=nB) ? gcd_1(nA,nB) : gcd_1(nB,nA);
}




// 辗转相除法
int gcd_2( int a, int b ){
    if( a >= b ){
        int r = a%b;
        return (r==0) ? b : gcd_2(b,r);
    }else{
        int r = b%a;
        return (r==0) ? a : gcd_2(a,r);
    }
}





}//~
#endif
