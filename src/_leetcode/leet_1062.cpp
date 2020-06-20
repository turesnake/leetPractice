/*
 * ====================== leet_1062.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1062. 最长重复子串
 */
#include "innLeet.h"


namespace leet_1062 {//~


// 这里的 最长重复子串，允许嵌套: "aaa" 的结果是 "aa"
// 重复子串 是一个连续区间， "abiiaiib" 这种，“ab” 就不算
// 这降低了难度

// 适当借鉴了 官方答案，使用了 暴力方案
// 一个小小的优化点是：
// 当之前获得一个 重复子串 最长长度后，
// 之后的遍历，一律在此基础上递增 


// 查找 重复字符串的方式没有变，还是 用 str.find(); str.rfind() 来实现


//   46%  100%
//  暴力解 其实很玄...
class S{
public:
    // 小写字母
    // 1 <= S.len <= 1500
    int longestRepeatingSubstring( std::string S ){

        int N = static_cast<int>(S.size());

        if(N==1){ return 0; }
        if(N==2){ return S[0]==S[1] ? 1 : 0; }

        int maxLen = 0;
        
        for( int l=0; l<N; l++ ){
            int r = l + maxLen; // 会比 现有 最长长度，再长1位
            for( ; r<N; r++ ){
                int len = r-l+1;
                if( S.rfind(std::string(S, l, len))==l ){ break; }
                maxLen = std::max( maxLen, len );
            }
        }
        return maxLen;
    }


    // 双指针 滑动窗口法   46%  100%
    // 远离上虽然有别于上面的 暴力法，
    // 但由于暴力法添加了 关键性的 优化，所以实际上，两个方法的执行细节是一样的...
    int longestRepeatingSubstring_2( std::string S ){

        int N = static_cast<int>(S.size());

        if(N==1){ return 0; }
        if(N==2){ return S[0]==S[1] ? 1 : 0; }

        int maxLen = 0;
        int l=0;
        int r=0;

        for(; r<N; r++ ){// r 步进
            int len = r-l+1;
            if( len < maxLen ){ continue; }// 优化，节省比较次数

            if( S.rfind(std::string(S, l, len))==l ){// 不符合
                l++;
            }else{// 符合
                maxLen = std::max( maxLen, len );
            }
        }
        return maxLen;


    }




};




//=========================================================//
void main_(){

    std::string s = "aaaaa";

    auto ret = S{}.longestRepeatingSubstring( s );

    cout<<"ret:"<<ret<<endl;


    
    debug::log( "\n~~~~ leet: 1062 :end ~~~~\n" );
}
}//~
