/*
 * ====================== leet_191.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 191. 位1的个数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_191 {//~


// n &= n-1; 
// 也能实现 尾部1 的去除工作 


// 54%， 100%
// 统计 二进制表达中，1的个数
// 用 lowBit 算法来 快速获得 低位的 1
class S{
public:
    int hammingWeight( uint32_t n ){

        int sum = 0;
        while(n>0){
            sum++;
            n -= n&(-n);
        }
        return sum;        
    }
};



//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 191 :end ~~~~\n" );
}
}//~
