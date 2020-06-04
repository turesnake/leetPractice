/*
 * ====================== leet_461.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 461. 汉明距离
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_461 {//~



class S{


// 100%, 100%
public:
    // 参数为正整数
    int hammingDistance( int x, int y ){

        int sum = 0;
        while( x!=0 || y!=0 ){
            if(x==0){
                for( ; y!=0; y>>=1 ){ if((y&1)==1){sum++;} }
            }else if(y==0){
                for( ; x!=0; x>>=1 ){ if((x&1)==1){sum++;} }
            }else{
                if( (x&1) != (y&1) ){ sum++; }
                x>>=1;
                y>>=1;
            }
        }
        return sum;
    }
};





//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 461 :end ~~~~\n" );
}
}//~
