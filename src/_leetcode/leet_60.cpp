/*
 * ====================== leet_60.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 60. 第k个排列
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_60 {//~



// 以 n! (n:[1,9]) 为边界，将 k 拆分为 数个段
// 然后拼装出 目标值


// 未来做...


class S{

struct Elem{
    int base {}; // 阶乘的底
    int num {}; // idx+1
};


    const std::vector<int> facts {
        1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880
    };


public:
    // 给定 n 的范围是 [ 1, 9 ]
    // 给定 k 的范围是 [ 1,  n! ]
    std::string getPermutation( int n, int k ){

       
        return "";
        
    }
};



//=========================================================//
void main_(){

    //auto ret = S{}.getPermutation( 5, 24 );
    //cout<<"ret:"<<ret<<endl;



    
    debug::log( "\n~~~~ leet: 60 :end ~~~~\n" );
}
}//~
