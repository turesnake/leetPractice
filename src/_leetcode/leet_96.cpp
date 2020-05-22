/*
 * ====================== leet_96.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 96. 不同的二叉搜索树
 */
#include "innLeet.h"


namespace leet_96 {//~





int numTrees( int n ){

    if( n==0 ){ return 0; }

    std::vector<int> dp ( std::max(3,n+1), -1 ); // 记录每种N，对应的 二叉树总数
    dp.at(0) = 1;//0号位空置, 因为会参与乘法，写1
    dp.at(1) = 1;
    dp.at(2) = 2;
    for( int eachN=3; eachN<=n; eachN++ ){// 依次计算 [1,n] 每种值，它的 二叉树总数
        int sum = 0;
        for( int i=0; i<eachN; i++ ){// 根节点下标
            int left = i-0; // 左子树个数
            int right = eachN-1-i; // 右子树个数
            sum += dp.at(left) * dp.at(right);
        }
        dp.at(eachN) = sum;
    }
    return dp.at(n);
}





//=========================================================//
void main_(){

    
    for( int i : { 0,1,2,3,4,5,6 } ){
        cout << i << "- " << numTrees(i) << endl;
    }

    
    

    debug::log( "\n~~~~ leet: 96 :end ~~~~\n" );
}
}//~
