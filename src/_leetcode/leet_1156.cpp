/*
 * ====================== leet_1156.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1156. 单字符重复子串的最大长度
 */
#include "innLeet.h"


namespace leet_1156 {//~


// dp[i].purelen: "aaa"
// dp[i].mixlen:  "abaaa"

// 如果一个 元素的 purelen == mixlen，说明前方没找到合适的链接区间 

// 官方提示有 滑动窗口法，暂时没研究 ...



//   79%   100%
class S{

struct Elem{
    int purelen {1}; // 不含异物区间长度
    int mixlen  {1}; // 含异物区间总长度
};

struct CE{
    int mmin {INT_MAX};
    int mmax {INT_MIN};
};


public:
    // 1 <= text.len <= 20000
    // 全为 小写字母 
    int maxRepOpt1( std::string text ){

        int N = static_cast<int>(text.size());
        if(N==1){ return 1; }
        if(N==2){ return text[0]==text[1] ? 2 : 1; }
        // 以下，超过 2 个元素

        std::vector<CE> chars (26, CE{}); // 记录每个字母的 左右极限
        std::vector<Elem> dp (N, Elem{});

        // [0]
        dp[0] = Elem{1,1};
        chars[text[0]-'a'].mmin = 0;
        chars[text[0]-'a'].mmax = 0;

        // [1]
        if( text[1]==text[0] ){
            dp[1] = Elem{ 2,2 };
            chars[text[1]-'a'].mmax = 1;
        }else{
            dp[1] = Elem{ 1,1 };
            chars[text[1]-'a'].mmin = 1;
            chars[text[1]-'a'].mmax = 1;
        }

        // [oth]
        for( int i=2; i<N; i++ ){// [i-2], [i-1], [i]

            auto &ce = chars[text[i]-'a'];
            ce.mmin = std::min( ce.mmin, i );
            ce.mmax = std::max( ce.mmax, i );

            if( text[i]==text[i-1] ){
                dp[i].purelen = dp[i-1].purelen+1;
                dp[i].mixlen = dp[i-1].mixlen+1;
                
            }else if( text[i]==text[i-2] ){// 中间隔了一位
                dp[i].purelen = 1;
                dp[i].mixlen = dp[i-2].purelen + 2;
                
            }else{
                // 自己是独立的
                dp[i] = Elem{ 1,1 };
            }

        }

        int outMax = 0;
        // 再次遍历，查找最大区间
        for( int i=0; i<N; i++ ){
            auto &ce = chars[text[i]-'a'];

            if( dp[i].purelen == dp[i].mixlen ){
                // 不存在 拼合区间
                if( (ce.mmin < i-dp[i].purelen+1) ||
                    (ce.mmax > i) ){
                    // 说明 pure 区间外，还有同值元素
                    outMax = std::max( outMax, dp[i].purelen+1 );
                }else{
                    // 所有同值字符，都在 本 pure 区间内了
                    outMax = std::max( outMax, dp[i].purelen );
                }
            }else{
                // 存在 拼合区间
                if( (ce.mmin < i-dp[i].mixlen+1) || 
                    (ce.mmax > i) ){
                    // 说明 mix 区间外，还有同值元素
                    outMax = std::max( outMax, dp[i].mixlen );
                }else{
                    // 所有同值字符，都在 本 mix 区间内了
                    // 但也只能获得 pure+1 
                    outMax = std::max( outMax, dp[i].purelen+1 );
                }
            }
        }
        return outMax;


    }
};


//=========================================================//
void main_(){

    std::string s = "aaabaaabaaaa";

    auto ret = S{}.maxRepOpt1(s);

    cout<<"ret:"<<ret<<endl;

    
    debug::log( "\n~~~~ leet: 1156 :end ~~~~\n" );
}
}//~
