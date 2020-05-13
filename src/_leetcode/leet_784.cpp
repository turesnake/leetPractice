/*
 * ====================== leet_784.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 784. 字母大小写全排列
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_784 {//~



// 44.58%, 100%
class S {
public:

    bool isLetter( char c_ ){
        return !((c_>='0')&&(c_<='9'));
    }

    bool isCap( char c_ ){
        return (c_>='A' && c_<='Z');
    }
 

    // idx_. 调用方希望自己开始处理的点，
    // 调用方并未检测，这个点上的 char，是否为 字母，
    // 调用方只保证，这个点之前的字符，都被处理过了
    void work(  std::vector<std::string> &strs_,
                std::string s_,
                int idx_
                ){

        // find fst letter
        int i=idx_;
        for( ; i<sSize; i++ ){
            if( isLetter(s_.at(i)) ){ 
                break; 
            }
        }

        // 要么是 idx_ 已经到底了，要么是 i自己遍历到底了
        if( i >= sSize ){
            strs_.push_back( s_ );
            return;
        }

        work( strs_, s_, i+1 );
        ( isCap(s_.at(i)) ) ?
                s_.at(i) += 'a'-'A' :
                s_.at(i) += 'A'-'a';
        work( strs_, s_, i+1 );
    }


    std::vector<std::string> letterCasePermutation( std::string S ) {
        this->sSize = static_cast<int>(S.size());
        std::vector<std::string> strs {};
        work( strs, S, 0 );
        return strs;
    }


private:
    int sSize {};

};




//=========================================================//
void main_(){

    auto ret = S{}.letterCasePermutation( "12345" );

    for( const auto &s : ret ){
        cout << s << endl;
    }



    debug::log( "\n~~~~ leet: 784 :end ~~~~\n" );
}
}//~

