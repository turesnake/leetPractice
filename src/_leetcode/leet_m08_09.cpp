/*
 * ====================== leet_m08_09.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 面试题 08.09. 括号
 */
#include "innLeet.h"


namespace leet_m08_09 {//~


// 每个状态，都完整地生成属于自己的 所有字符串


//   57%   100%
class S{
public:
    std::vector<std::string> generateParenthesis(int n){

        if(n==0){ return {}; }
        if(n==1){ return std::vector<std::string>{ "()" }; }

        std::vector<std::vector<std::string>> dp (n+1, std::vector<std::string>{} );

        dp[0].push_back( "" );
        dp[1].push_back( "()" );
    
        for( int i=2; i<=n; i++ ){
            for( int l=1; l<=i; l++ ){
                int r = i-l;
                for( auto &ls : dp[l-1] ){
                    for( auto &rs : dp[r] ){
                        dp[i].emplace_back( "(" + ls + ")" + rs );
                    }
                }
            }
        }
        return dp[n];


    }
};



//=========================================================//
void main_(){

    auto ret = S{}.generateParenthesis( 3 );

    cout<<"ret:"<<endl; for( const auto &s : ret ){ cout<<s<<endl; }


    
    debug::log( "\n~~~~ leet: m08_09 :end ~~~~\n" );
}
}//~
