/*
 * ====================== leet_267.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 267. 回文排列 II
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_267 {//~


// 烦死



//   100%   100%
class S{

    std::unordered_map<char,int> chars {};
    std::vector<std::string> outStrs {};
    std::string str {};// 回溯法 操作对象
    int halfN {};

    void work( int idx ){
        if( idx == halfN ){
            outStrs.push_back( str );// copy
            return;
        }
        for( auto &[c,n] : chars ){
            if( n==0 ){ continue; }
            str.push_back(c);
            n--;
            work( idx+1 );
            str.pop_back();
            n++;
        }        
    }


public:
    std::vector<std::string> generatePalindromes( std::string s ){
        
        for( char c : s ){
            chars[c]++;
        }

        int oddNum = 0;
        int midC {};
        for( auto [c,n] : chars ){
            if( (n&1)==1 ){ oddNum++; midC=c; }
        }
        if( oddNum>1 ){ return {}; }

        //===//
        if( oddNum==1 ){
            chars[midC]--; // 减去mid位，现在，chars 中所有非0元素，值都是偶数
            if( chars[midC]==0 ){
                chars.erase(midC);
            }
        }

        for( auto &[c,n] : chars ){
            n>>=1; // 减半
            halfN += n;
        }

        work(0);

        // 补完 mid 和 后半段
        for( auto &str : outStrs ){
            std::string r ( str.rbegin(), str.rend() );
            if( oddNum==1 ){ str.push_back(midC); }
            str.append( std::move(r) );
        }
        return outStrs;
    }
};




//=========================================================//
void main_(){

    auto ret = S{}.generatePalindromes( "aaaabbcc" );

    cout<<"ret:"<<endl;
    for( auto &s : ret ){
        cout<<s<<endl;
    }




    debug::log( "\n~~~~ leet: 267 :end ~~~~\n" );
}
}//~
