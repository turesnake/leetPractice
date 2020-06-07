/*
 * ====================== leet_402.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 402. 移掉K位数字
 */
#include "innLeet.h"


namespace leet_402 {//~

// 一周目
// 有点难写
std::string removeKdigits( std::string num, int k ) {

    if( k<=0 ){ return num; }
    if( k>=static_cast<int>(num.size()) ){ return "0"; }

    std::deque<int> que {};
    for( const char c : num ){
        int newV = static_cast<int>(c-'0');
        while( k>0 && !que.empty() && (que.back()>newV) ){
            que.pop_back();
            k--;
        }
        que.push_back(newV);
    }
 
    std::string out {};
    while( !que.empty() ){
        int v = que.front();
        que.pop_front();
        if( !(out.empty() && v==0) ){
            out += static_cast<char>('0'+v);
        }
    }

    if( k >= static_cast<int>(out.size()) ){ return "0"; }
    if( k>0 ){ out.erase( out.size()-k,k ); }
    return out;
}




// 二周目
// 单调栈，递增栈  68%, 100%
class S2{
public:
    // k 一定有效， num 可空
    // num 不包含前导0
    std::string removeKdigits( std::string num, int k ) {

        if( num.empty() ){ return ""; }
        int N = static_cast<int>(num.size());
        std::deque<char> stk {};
        int count = k;// 倒序
        int i=0;
        for( ; i<N; i++ ){
            char curC = num.at(i);
            if( stk.empty() ){
                stk.push_back( curC );
                continue;
            }
            // 清理掉所有 大于 curC 的栈值
            while( !stk.empty() && curC<stk.back() && count>0 ){
                stk.pop_back();
                count--;
            }// 可能会用光所有 count，也可能不会
            // 压入新值
            stk.push_back(curC);
        }// 所有值都被彻底 压入 
        while( !stk.empty() && count>0  ){
            stk.pop_back();
            count--;
        }
        // 去掉所有前导0
        while( !stk.empty() && stk.front()=='0' ){
            stk.pop_front();
        }
        return stk.empty() ? "0" : std::string(stk.begin(), stk.end());
    }
};



//=========================================================//
void main_(){

    auto ret = removeKdigits( "1234567890", 9 );
    debug::log( "ret = {}", ret );


    debug::log( "\n~~~~ leet: 402 :end ~~~~\n" );
}
}//~
