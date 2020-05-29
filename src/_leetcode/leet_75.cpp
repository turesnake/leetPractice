/*
 * ====================== leet_75.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 75. 颜色分类
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_75 {//~


// 荷兰国旗问题
// 三指针 
void sortColors( std::vector<int>& nums ){


    
    // 待实现 ...
    
}


//=========================================================//
void main_(){

    std::vector<int> v { 2,0,2,1,1,0 };

    sortColors(v);

    for( int i : v ){
        cout<<i<<", ";
    }cout<<endl;



    debug::log( "\n~~~~ leet: 75 :end ~~~~\n" );
}
}//~
