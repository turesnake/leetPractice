/*
 * ====================== fast_product.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.02
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 俄罗斯农民乘法
 */
#ifndef TPR_FAST_PRODUCT_H
#define TPR_FAST_PRODUCT_H
#include "pch.h"

namespace tpr_fast_product{//~



// 俄罗斯农民乘法 
// b 不能为负数
int product_1( int a, int b ){
    int sum {0};
    for( int i=0; b!=0; i++, b>>=1 ){
        if(b&1){ sum += a<<i; }
    }
    return sum;
}




}//~
#endif
