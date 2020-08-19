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

// 最优算法：马拉车
// 一个最长回文子串，如果长度为 len, 那么它包含的回文个数为 (len+1)/2
// 通过这个规律，可以获得最优实现


// 马拉车算法   100%    63%
class S2{
public:
    // 输入的字符串长度不会超过 1000
    int countSubstrings( std::string s ){

        int Ns = static_cast<int>(s.size());
        int N = Ns*2+1;

        std::string ss (N,'#');
        for( int i=0; i<Ns; i++ ){
            ss[i*2+1] = s[i];
        }
        std::vector<int> w (N,0);// w[0]==0
        
        int center = 0;
        int maxR = 0;
        int ans = 0;

        for(int i=1; i<N; i++ ){
            if( i<maxR ){
                int mirror = center*2-i;
                w[i] = std::min( w[mirror], maxR-i );
            }

            int l = i - w[i] - 1;
            int r = i + w[i] + 1;
            for(; l>=0 && r<N && ss[l]==ss[r]; l--,r++,w[i]++ ){}

            //--- 更新数据 ---//
            if( i+w[i] > maxR ){
                maxR = i+w[i];
                center = i;
            }
            ans += (w[i]+1)/2;// 收集回文个数
        }
        return ans;

    }
};





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




//=========================================================//
void main_(){

    cout << S{}.countSubstrings( "abccbe" ) << endl;
    



    debug::log( "\n~~~~ leet: 647 :end ~~~~\n" );
}
}//~
