/*
 * ====================== leet_409.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 409. 最长回文串
 */
#include "innLeet.h"



namespace leet_409 {//~


// 所有 偶数个数的字符，都可以被收集
// 奇数个数的字符，统统削掉头部的1后，被收集
// 如果存在奇数，要在总数里 加 1
class S {

    // 以 最紧凑的方式，存储 所有字符 个数 
    std::vector<int> letters {};// 先大写，后小写

public:

    void insert( char c ){
        if( c>='A' && c<='Z' ){// 大写
            letters.at(c-'A')++;
        }else{// 小写
            letters.at(c-'a'+26)++;
        }
    }

    int longestPalindrome( std::string s ){

        if( s.empty() || s.size()==1 ){ return s.size(); }

        letters.resize( 26*2, 0 );// 正好装满 大小写字母
        for( const char c : s ){
            insert( c );
        }
        int sum {0};
        bool isFindOdd {false};
        for( const int i : letters ){
            if( i == 0 ){ continue; }
            if(i%2==0){
                sum += i;
            }else{
                sum += i-1;
                if( !isFindOdd ){ isFindOdd=true; }
            }
        }
        return isFindOdd ? (sum+1) : sum;
    }
};







//=========================================================//
void main_(){

    auto ret = S{}.longestPalindrome( "civillmtheearth" );
    cout << "ret = " << ret << endl;

    

    debug::log( "\n~~~~ leet: 409 :end ~~~~\n" );
}
}//~

