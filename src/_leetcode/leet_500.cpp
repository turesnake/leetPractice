/*
 * ====================== leet_500.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.23
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 500. 键盘行
 */
#include "innLeet.h"


namespace leet_500 {//~


// 方法1 
std::vector<std::string> findWords( std::vector<std::string>& words ){

    std::vector<std::unordered_set<char>> sets {
        { 'Q','W','E','R','T','Y','U','I','O','P', 'q','w','e','r','t','y','u','i','o','p' },
        { 'A','S','D','F','G','H','J','K','L', 'a','s','d','f','g','h','j','k','l' },
        { 'Z','X','C','V','B','N','M', 'z','x','c','v','b','n','m' }
    };

    std::vector<std::string> outs {};

    for( const auto &s : words ){
        std::unordered_set<char> *setp {nullptr};
        for( auto &ct : sets  ){
            if( ct.find(s.front()) != ct.end() ){
                setp = &ct;
                break;
            }
        }
        assert( setp );
        bool isLegel {true};
        for( char c : s ){
            if( setp->find(c) == setp->end() ){
                isLegel = false;
                break;
            }
        }
        if( isLegel ){ outs.push_back(s); }
    }
    return outs;
}



// 方法2，
// 存储为 umap <char,lines> 反向比较行数
// 更简单





//=========================================================//
void main_(){

    std::vector<std::string> v {
        "QWERTYUIOPqwertyuiop", 
        "ASDFGHJKLasdfghjkl", 
        "ZXCVBNMzxcvbnm"
    };

    auto ret = findWords( v );

    for( const auto &s : ret ){
        cout << s << endl;
    }
    



    debug::log( "\n~~~~ leet: 500 :end ~~~~\n" );
}
}//~
