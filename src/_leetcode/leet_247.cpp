/*
 * ====================== leet_247.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 247. 中心对称数 II
 */
#include "innLeet.h"
#include "GraphNode1.h"


namespace leet_247 {//~


//   dfs  79%  11%
class S{

    const std::vector<std::string> pairs { "00", "11", "69", "88", "96" };
    const std::vector<char> odds { '0', '1','8' };

    std::vector<std::string> ans {};
    std::string str {};
    int N {};

    // idx: midleft->0
    void handle_even( int idx ){
        if( idx==-1 ){
            ans.push_back(str);
            return;
        }
        for( const auto &s : pairs ){
            if( idx==0 && s[0]=='0' ){ continue; }   
            str[idx] = s[0];
            str[N-1-idx] = s[1];
            handle_even(idx-1);
        }
    }

public:
    std::vector<std::string> findStrobogrammatic( int n ){

        if(n==0){ return {""}; }

        N = n;
        str.resize( N,'0' );
        int mid = (n-1)/2;// both odd/even
        if( (n&1)==1 ){
            for( char c : odds ){
                str[mid] = c;
                handle_even( mid-1 );
            }
        }else{
            handle_even(mid);
        }
        return ans;
    }
};


//=========================================================//
void main_(){


    

    debug::log( "\n~~~~ leet: 247 :end ~~~~\n" );
}
}//~
