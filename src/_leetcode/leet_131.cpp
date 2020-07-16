/*
 * ====================== leet_131.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 131. 分割回文串
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_131 {//~


// 先利用 记忆化思维，生成一个 二维dp数组，
// dp[k][i] 表示，i位起始的，长度为k的 区间，是不是回文

// 然后，dfs + 回溯，生产 所有 解法



//   96%   100%
class S{

    std::string *sp {nullptr};
    std::vector<std::vector<char>> dp {};// 0:非回文 1:是回文

    std::vector<std::vector<std::string>> outs {};
    std::vector<std::string> v {};

    int N {};

    void work( int idx ){
        if( idx==N ){
            outs.push_back( v );//copy
            return;
        }
        int len = N-idx;
        for( int h=1; h<=len; h++ ){
            if( dp[h][idx]==1 ){
                v.emplace_back( *sp, idx, h );
                work( idx+h );
                v.pop_back();
            }
        }
    }

public:
    std::vector<std::vector<std::string>> partition( std::string s ){

        if( s.empty() ){ 
            outs.push_back( std::vector<std::string>{} );
            return outs; 
        }
        N = static_cast<int>(s.size());
        sp = &s;
        dp.resize( N+1, std::vector<char>(N, 0) );// [0]层 空置

        // dp[1][w]
        for( int w=0; w<N; w++ ){
            dp[1][w] = 1;
        }
        // dp[2][w]
        for( int w=0; w<=N-2; w++ ){// [w], [w+1]
            if( s[w]==s[w+1] ){
                dp[2][w]=1;
            }
        }
        // dp[h][w], h>=3
        for( int h=3; h<=N; h++ ){
            for( int w=0; w<=N-h; w++ ){
                if( s[w]==s[w+h-1] && dp[h-2][w+1]==1 ){
                    dp[h][w] = 1;
                }
            }
        }
                /*
                cout<<"dp:"<<endl;
                for( auto &c : dp ){ for( int i : c ){ cout<<i<<", "; }cout<<endl;
                }cout<<"------"<<endl;
                */
        work(0);
        return outs;
    }
};









//=========================================================//
void main_(){

    auto ret = S{}.partition( "bakaa" );

    cout<<"ret:"<<endl;
    for( auto &c : ret ){
        for( const auto &s : c ){
            cout<<s<<", ";
        }cout<<endl;
    }



    debug::log( "\n~~~~ leet: 131 :end ~~~~\n" );
}
}//~
