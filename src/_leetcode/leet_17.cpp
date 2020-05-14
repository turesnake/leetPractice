/*
 * ====================== leet_17.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 17. 电话号码的字母组合
 */
#include "innLeet.h"


namespace leet_17 {//~



class S {

    std::unordered_map<char, std::vector<char>> datas {
        { '2', { 'a','b','c' } },
        { '3', { 'd','e','f' } },
        { '4', { 'g','h','i' } },
        { '5', { 'j','k','l' } },
        { '6', { 'm','n','o' } },
        { '7', { 'p','q','r','s' } },
        { '8', { 't','u','v' } },
        { '9', { 'w','x','y','z' } }
    };
    std::vector<std::string> outs {};
    std::vector<std::vector<char>*> cPtrs {}; // 容器指针
    std::string str {}; //要装配的 str
    int digitsSize {};

public:

    // idx_ 本回合要装配的 数据
    void work( int idx_ ){
        if( idx_ == digitsSize ){// idx 指向尾后了
            outs.push_back( str );
            return;
        }
        auto &container = *(cPtrs.at(idx_));
        for( const char c : container ){
            str += c;
            work( idx_+1 );
            str.pop_back();
        }
    }

    std::vector<std::string> letterCombinations( std::string digits ) {
        this->outs.clear();
        if( digits.empty() ){ return this->outs; }
        this->cPtrs.clear();
        this->str.clear();
        this->digitsSize = static_cast<int>(digits.size());
        for( const char c : digits ){
            cPtrs.push_back( &datas.at(c) );
        }
        work( 0 );
        return this->outs;
    }
};






//=========================================================//
void main_(){

    auto ret = S{}.letterCombinations( "23" );

    cout << "retNum = " << ret.size() << endl;
    for( const auto &s : ret ){
        cout << s << endl;
    }
    

    debug::log( "\n~~~~ leet: 17 :end ~~~~\n" );
}
}//~
