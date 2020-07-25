/*
 * ====================== leet_246.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 246. 中心对称数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_246 {//~

// 6-9
// 1-1
// 8-8


// 100%  100%
class S{
public:
    bool isStrobogrammatic( std::string num ){

        if( num.empty() ){ return true; }
        int N = static_cast<int>(num.size());
        int l=0;
        int r=N-1;
        for(; l<r; l++,r-- ){
            if( (num[l]=='6' && num[r]=='9') ||
                (num[l]=='9' && num[r]=='6') ||
                (num[l]=='0' && num[r]=='0') ||
                (num[l]=='1' && num[r]=='1') ||
                (num[l]=='8' && num[r]=='8')
                ){
                continue;
            }else{
                return false;
            }
        }
        if( l==r ){ return num[l]=='0' || num[l]=='1' || num[l]=='8'; }
        return true;
    

    }
};


//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 246 :end ~~~~\n" );
}
}//~
