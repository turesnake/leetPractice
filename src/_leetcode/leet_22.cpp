/*
 * ====================== leet_22.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.13
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 22. 括号生成
 */
#include "innLeet.h"


namespace leet_22 {//~



class S {
public:

    // 目标字符串是否合法
    // 目标字符串是不完整的
    // 可以确保的是，'(' 数量多于 ')'
    bool isLegel( const std::string &s_ ){
        if( s_.empty() ){ return true; }
        // 踢掉尾部所有的 '('
        int lstRight= static_cast<int>(s_.size())-1;
        for( ; (lstRight>=0) && (s_.at(lstRight)=='('); lstRight-- ){}
        if( lstRight < 0 ){ return true; }// 全是 '('

        int stkNum {0};
        for( int i=0; i<=lstRight; i++ ){
            if( s_.at(i) == '(' ){
                stkNum++;
            }else{
                if( stkNum <= 0 ){ return false; }
                stkNum--;
            }
        }
        return true; // stkNum 允许有剩余
    }



    // 回溯
    void work( std::string s_, int LLeftNum_, int RLeftNum_ ){

        if( RLeftNum_ < LLeftNum_ ){ return; } // 右括号太多了
        if( !isLegel(s_) ){ return; } // 现有字符串已经非法

        if( LLeftNum_ == 0 ){
            s_.insert( s_.end(), RLeftNum_, ')' );//补完
            assert( isLegel(s_) ); // 一定正确
            this->strs.push_back( s_ );
            return;
        }
        work( s_+"(", LLeftNum_-1, RLeftNum_ );
        work( s_+")", LLeftNum_, RLeftNum_-1 );
    }



    std::vector<std::string> generateParenthesis( int n ){
        this->strs.clear();
        if( n==0 ){ return this->strs; }
        if( n==1 ){ this->strs.push_back("()"); return this->strs; }
        work( "", n, n );
        return this->strs;
    }

private:
    std::vector<std::string> strs {};
};







//=========================================================//
void main_(){

    /*
    auto ret = S{}.isLegel( std::string{ "(())" } );
    debug::log( "ret = {}", ret );
    */

    
    auto ret = S{}.generateParenthesis( 4 );
    cout << "retNum = " << ret.size() << endl;
    for( const auto &s : ret ){
        cout << s << endl;
    }
    



    debug::log( "\n~~~~ leet: 22 :end ~~~~\n" );
}
}//~
