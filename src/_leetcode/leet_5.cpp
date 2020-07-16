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




// 马拉车版    97%   100%
class S2{
public:
    std::string longestPalindrome( std::string s ){

        int Ns = static_cast<int>(s.size());

        // 预处理字符串
        std::string v ( Ns*2+1, '#' );
        for( int i=0; i<Ns; i++ ){
            v[i*2+1] = s[i];
        }
        int Nv = static_cast<int>(v.size());

        std::vector<int> mv (Nv, 0);
        int center = 0;
        int maxR = 0;// 可以设为最小值，不影响最初的运算
        int maxLen = 1;
        int start = 0;

        for( int i=0; i<Nv; i++ ){

            if( i < maxR ){
                int mirror = center*2-i;
                mv[i] = std::min( mv[mirror], maxR-i );
            }

            int l = i-mv[i]-1;
            int r = i+mv[i]+1;
            for(; l>=0 && r<Nv && v[l]==v[r]; mv[i]++,l--,r++ ){}

            // 更新数据
            if( i+mv[i]>maxR ){
                maxR = i+mv[i];
                center = i;
            }

            if( mv[i]>maxLen ){
                maxLen = mv[i];
                start = (i-mv[i])/2;
            }
        }
        return std::string( s, start, maxLen );
        
    }
};






//=========================================================//
void main_(){


    cout << longestPalindrome_1( "cbaabcdcbabc" ) << endl;
    


    debug::log( "\n~~~~ leet: 5 :end ~~~~\n" );
}
}//~
