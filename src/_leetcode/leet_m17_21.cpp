/*
 * ====================== leet_m17_21.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.09
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 17.21. 直方图的水量
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_m17_21 {//~


// 此题就是 接雨水
// 尝试再做一遍 


// 97%  100%
class S{
public:
    int trap( std::vector<int>& height ){


        if( height.size()<=2 ){ return 0; }
        int N = static_cast<int>(height.size());
        int maxSum = 0;
        int l=0;
        int r=N-1;
        while( l<r ){
            int vl = height.at(l);
            int vr = height.at(r);
            int minH = std::min(vl,vr);
            if( vl <= vr ){
                for( ; l<r && height.at(l)<=minH; l++ ){
                    maxSum += minH - height.at(l);
                }
            }else{
                for( ; l<r && height.at(r)<=minH; r-- ){
                    maxSum += minH - height.at(r);
                }
            }
        }
        return maxSum;
    }
};




//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: m17_21 :end ~~~~\n" );
}
}//~
