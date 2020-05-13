/*
 * ====================== leet_11.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 盛最多水的容器  
 */
#include "innLeet.h"


namespace leet_11 {//~




// 至少有 2个以上元素
int maxArea( std::vector<int>& height ) {

    int maxArea {0};
    int area {};
    int hLen {};
    int tLen {};

    int head = static_cast<int>(height.size())-1;
    int tail = 0;

    while( tail < head ){

        hLen = height.at(head);
        tLen = height.at(tail);

        area = (head-tail) * std::min(hLen, tLen);
        maxArea = std::max( maxArea, area );

        (tLen<hLen) ?
                tail++ :
                head--;

    }

    return maxArea;
}



//=========================================================//
void main_(){

    //std::vector heights { 1,1,1 };
    std::vector heights { 1,8,6,2,5,4,8,3,7 };
    int ret = maxArea( heights );

    cout << "ret = " << ret << endl;


    debug::log( "\n~~~~ leet: 11 :end ~~~~\n" );
}
}//~
