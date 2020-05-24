/*
 * ====================== leet_647.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.24
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 647. 回文子串
 */
#include "innLeet.h"


namespace leet_647 {//~



// 动态规划： 27% 78%
// 思路，一串字符是否为回文，-1- 比较两端字母，-2- 查表确认中间段是否为回文 
class S{

    std::vector<std::vector<char>> dp {};// 1:true

    char &dp_at( int j, int i ){
        return dp.at(j-2).at(i);
    }

    void dp_resize( int N ){
        dp.resize( N+1 - 2 );//[0],[1] 层被取消
        for( int n=2; n<=N; n++ ){
            dp.at(n-2).resize( N-n+1 );
        }
    }

    //目标区间是否为 回文
    bool isTarget( const std::string &s, int i, int len ){
        if( len==1 ){ return true; } // 1 个字母
        int l = i;
        int r = i+len-1;
        if( s.at(l) != s.at(r) ){ return false; }
        return (len<=3) ? 
                true : // 2,3 个字母,无需检查内部段
                dp_at( len-2, l+1 )==1; // 检查内部段
    }

public:

    int countSubstrings( std::string s ){

        if( s.size()<2 ){ return s.size(); }
        int N = static_cast<int>(s.size());
        dp_resize(N);
        int sum = N; // 单字母全部满足
        for( int n=2; n<=N; n++ ){
            for( int i=0; i<N-n+1; i++ ){// 遍历 本层所有元素
                if( isTarget(s, i, n) ){
                    sum++;
                    dp_at(n,i) = 1;
                }else{
                    dp_at(n,i) = 0;
                }
            }
        }
        /*
        cout <<"dp"<<endl;
        for( auto &c : dp ){
            for( char i : c ){
                cout << i <<",";
            }
            cout <<endl;
        }
        cout <<"======"<<endl;
        */
        return sum;
    }
};


// 方法2:中心扩展法
// 从任意1字母开始，向两侧扩展，直到发现不再是 回文子段 为止。适用于 奇数个字母时
// 偶数个字母时，可以先用 [i,i+1] 两个字母起始





//=========================================================//
void main_(){

    cout << S{}.countSubstrings( "abccbe" ) << endl;
    



    debug::log( "\n~~~~ leet: 647 :end ~~~~\n" );
}
}//~
