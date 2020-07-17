/*
 * ====================== leet_1147.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1147. 段式回文
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1147 {//~



//   100%   100%
class S{
public:
    int longestDecomposition( std::string text ){

        if( text.empty() ){ return 0; }

        int N = static_cast<int>(text.size());
        int l=0;
        int r=N-1;
        int sum = 0;// 至少整体算一个

        while( l<r ){
            int len = 1;
            bool isFind = false;
            for(; l<r; r--,len++ ){
                if( text[l]!=text[r] ){ continue; }
                // 找到一个 匹配项，当场检查 是不是 完全匹配的
                bool isSame = true;
                for( int i=1; i<len; i++ ){
                    if( text[l+i]!=text[r+i] ){
                        isSame = false;
                        break;
                    }
                }
                if( isSame ){ isFind=true; break; }
                // 若并不完全匹配，则继续查找
            }
            if( !isFind ){ break; }// 目标区间没相同的
            //---//
            sum += 2; 
            l += len;
            r--;
        }
        if( l==r ){ sum++; }
        return sum;



    }
};




//=========================================================//
void main_(){

    auto ret = S{}.longestDecomposition( "vwsuvmbwknmnvwsuvmbwk" );

    cout<<"ret:"<<ret<<endl;





    debug::log( "\n~~~~ leet: 1147 :end ~~~~\n" );
}
}//~
