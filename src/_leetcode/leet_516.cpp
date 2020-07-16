/*
 * ====================== leet_516.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.24
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 516. 最长回文子序列
 */
#include "innLeet.h"


namespace leet_516 {//~





//=======================================================//
// 5.34% 75% 
// 思路：两指针指向 字符串的两端，依次计算，[l][r] 及其外侧区域的 “最长回文字母”个数
// 然后 存储在 dp表中，填满这个 dp表，最后做依次总体筛选
class S{

    std::vector<std::vector<int>> dp {};
    // 压缩版布局
    // 为了节省 dp 空间而做得设置
    // 缺点是 dp 变得不直观了
    int &dp_at( int l, int r ){
        return dp.at(r).at(l); 
    }
    void dp_resize( int N ){
        dp.resize( N );
        for( int i=0; i<N; i++ ){
            dp.at(i).resize( i+1, -1 );
        }
    }
    
public:
    int longestPalindromeSubseq( std::string s ){

        if( s.size()<2 ){ return s.size(); }
        int N = static_cast<int>(s.size());
        dp_resize(N);
        int fst = 0;
        int lst = N-1;
        //[fst][r] <-
        dp_at( fst, lst ) = s.at(fst)==s.at(lst) ? 2 : 0;
        for( int r=lst-1; r>=fst; r-- ){
            if( fst==r ){ 
                dp_at(fst,r) = 1; // 单一字母在两端，无法外延了
            }else{            
                dp_at(fst,r) = (dp_at(fst,r+1)==2) ?
                                2 :
                                s.at(fst)==s.at(r) ? 2 : 0;

            }
        }
        //[l][lst] ->
        for( int l=fst+1; l<=lst; l++ ){
            if( l==lst ){
                dp_at(l,lst) = 1; // 在两端，无法外延了
            }else{
                dp_at(l,lst) = (dp_at(l-1,lst)==2) ?
                                2 :
                                s.at(l)==s.at(lst) ? 2 : 0;
            }
        }
        // 主数据 
        for( int l=fst+1; l<=lst; l++ ){// 每行
            for( int r=lst-1; r>=l; r-- ){ // l==r 的情况 后面统一实现 
                if( l==r ){
                    dp_at(l,r) = 1 + dp_at(l-1,r+1);
                }else{
                    dp_at(l,r) = (s.at(l)==s.at(r)) ?
                                    2 + dp_at(l-1,r+1) :
                                    std::max(dp_at(l-1,r), dp_at(l,r+1));
                }
            }
        }
        int mmax {INT_MIN};
        for( int i=fst; i<=lst; i++ ){
            mmax = std::max( mmax, dp_at(i,i) );//奇数个
            if( i!=lst ){
                mmax = std::max( mmax, dp_at(i,i+1) );//偶数个
            }
        }
        /*
        //-------------------
        cout << "dp:" << endl;
        for( auto &c : dp ){ for( int i : c ){ cout << i << ",  "; } cout <<endl;}
        */
        return mmax;
    }


};


//=======================================================//
// 方法2: 借用 1143 题现成答案
// 反转一份 字符串，求两 字符串 最长公共子序列
class S2{

    // 1143 题 求 两个字符串 最长公共子序列
    // 两参数字符串 等长
    int longestCommonSubsequence_2( std::string &text1, std::string &text2 ){
        int N = static_cast<int>(text1.size());// w [1,1000]
        std::vector<int> dp1 ( N+1, 0 );
        std::vector<int> dp2 ( N+1, 0 );
        auto *fst = &dp1;
        auto *lst = &dp2;
        for( int j=1; j<=N; j++ ){// [1,N+1]   text2
            for( int i=1; i<=N; i++ ){// [1,N+1]  text1
                int up = fst->at(i);
                int left = lst->at(i-1);
                int corner = text1.at(i-1)==text2.at(j-1) ? fst->at(i-1)+1 : INT_MIN;
                lst->at(i) = std::max(std::max(up,left),corner);
            }
            std::swap(fst,lst);
        }
        return fst->back();
    }

public:
    int longestPalindromeSubseq( std::string s ){
        std::string rs ( s.rbegin(), s.rend() );// 倒序
        return longestCommonSubsequence_2( s, rs);
    }
};



//=======================================================//
// 方法3，看起来是对 方法1 的简化
// 别人的，暂未彻底研究...
class S3{
public:
    int longestPalindromeSubseq( std::string s ){

        int N = s.size();
        std::vector<std::vector<int> > dp(N, std::vector<int>(N, 0));
        for (int i = 0; i < N; ++i) dp[i][i] = 1;
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i + len - 1 < N; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = std::max( dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        //-------------------
        cout << "dp:" << endl;
        for( auto &c : dp ){
            for( int i : c ){ cout << i << ",  "; }
            cout <<endl;
        }
        cout << "=====" << endl;

        return dp[0][N - 1];
    }
};






//=========================================================//
void main_(){

    

    /*
    std::vector<std::string> ss {
        "", "a", "ab", "aba", "abab", "aaba", "aaaba", "aaaaba", "cbaabcdcbabc"
    };
    */

    std::vector<std::string> ss {
        "abab"
    };

    for( auto &s : ss ){
        //cout << s << " = " << S{}.longestPalindromeSubseq(s) << endl;
        cout << s << " = " << S3{}.longestPalindromeSubseq(s) << endl;
    }




    


    debug::log( "\n~~~~ leet: 516 :end ~~~~\n" );
}
}//~
