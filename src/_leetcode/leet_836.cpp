/*
 * ====================== leet_836.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.13
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 836. 矩形重叠
 */
#include "innLeet.h"


namespace leet_836 {//~


// 先检测 y轴投影，再检测 x轴投影

class S{
public:
    bool isRectangleOverlap( std::vector<int>& rec1, std::vector<int>& rec2 ){
        
        //== 检测 Y轴 投影是否相交 ==//
        if( rec1.at(1) <= rec2.at(1) ){
            if( rec1.at(3) <= rec2.at(1) ){ return false; }
        }else{
            if( rec2.at(3) <= rec1.at(1) ){ return false; }
        }
        //== 检测 X轴 投影是否相交 ==//
        if( rec1.at(0) <= rec2.at(0) ){
            if( rec1.at(2) <= rec2.at(0) ){ return false; }
        }else{
            if( rec2.at(2) <= rec1.at(0) ){ return false; }
        }
        return true;
    }
};




//=========================================================//
void main_(){

    


    debug::log( "\n~~~~ leet: 836 :end ~~~~\n" );
}
}//~
