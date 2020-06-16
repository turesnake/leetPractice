/*
 * ===================== leet_m16_16.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.16
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 16.16. 部分排序
 */
#include "innLeet.h"


namespace leet_m16_16 {//~



//  47%  100%
class S{
public:
    // 0 <= len(array) <= 100,0000
    std::vector<int> subSort( std::vector<int>& array ){

        if( array.empty() ){ return {-1,-1}; }
        int N = static_cast<int>(array.size());

        // 反向遍历，寻找区间 l 边界
        bool isFind = false;
        int l = N-1;
        int mmin = array.at(N-1);
        for( int i=N-2; i>=0; i-- ){
            int v = array.at(i);
            if( v==mmin ){ continue; }
            if( v<mmin ){
                mmin = v;
            }else{// v>mmin
                if(!isFind){ isFind = true; }
                l = i;
            }
        }
        if(!isFind){ return {-1,-1}; }// not find

        // 正向遍历，寻找区间 r 边界
        int r=0;
        int mmax = array.at(0);
        for( int i=1; i<N; i++ ){
            int v = array.at(i);
            if( v==mmax ){ continue; }
            if( v>mmax ){
                mmax = v;
            }else{// v<mmax
                r = i;
            }
        }
        return {l,r};

    }
};




//=========================================================//
void main_(){


    debug::log( "\n~~~~ leet: m16_16 :end ~~~~\n" );
}
}//~
