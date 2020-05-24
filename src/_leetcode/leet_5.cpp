/*
 * ====================== leet_5.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.24
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 5. 最长回文子串
 */
#include "innLeet.h"


namespace leet_5 {//~


// 中心扩展法  71.29% 100%
// 优点，无需像 动态规划一样 开辟 dp 空间
std::string longestPalindrome_1( std::string s ){

    if( s.size()<2 ){ return s; }
    // 以下，字母个数一定大于等于 2
    int N = static_cast<int>(s.size());
    int fst = 0;
    int lst = N-1;
    int l {};
    int r {};
    int len {};
    int maxLen {1};
    int targetIdx {0};
    for( int i=0; i<N; i++ ){// each char
        //=奇数=
        l = i-1;
        r = i+1;
        for( ; l>=fst && r<=lst && s.at(l)==s.at(r); l--,r++ ){
            len = r-l+1;
            if( len > maxLen ){// 每次都更新，效率不高
                maxLen = len;
                targetIdx = l;
            }
        }
        //=偶数=
        if( i<lst && s.at(i)==s.at(i+1) ){// 非尾字符，且中心2字符相同 时
            if( 2 > maxLen ){// 每次都更新，效率不高
                maxLen = 2;
                targetIdx = i;
            }
            l = i-1;
            r = i+2;
            for( ; l>=fst && r<=lst && s.at(l)==s.at(r); l--,r++ ){
                len = r-l+1;
                if( len > maxLen ){// 每次都更新，效率不高
                    maxLen = len;
                    targetIdx = l;
                }
            }
        }
    }
    return std::string( s, targetIdx, maxLen );
}




// 动态规划
// 未实现 ...






//=========================================================//
void main_(){


    cout << longestPalindrome_1( "cbaabcdcbabc" ) << endl;
    


    debug::log( "\n~~~~ leet: 5 :end ~~~~\n" );
}
}//~
