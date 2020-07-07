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



class S{


    std::vector<int> *np {nullptr};

    int l {};
    int r {};



public:
    int singleNonDuplicate( std::vector<int>& nums ){

        np = &nums;

        l = 0;
        r = static_cast<int>(nums.size())-1;


        // 未完...



        return 0;
        

    }
};



//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 540 :end ~~~~\n" );
}
}//~
