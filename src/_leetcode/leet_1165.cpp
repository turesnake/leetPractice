/*
 * ====================== leet_1165.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1165. 单行键盘
 */
#include "innLeet.h"


namespace leet_1165 {//~



class S{
public:
    // keyboard.len == 26
    // keyboard 按某种特定顺序排列，并包含每个小写英文字母一次。
    // 1 <= word.len <= 10^4
    // word[i] 是一个小写英文字母
    int calculateTime( std::string keyboard, std::string word) {

        std::unordered_map<char,int> umap {};
        int Nk = static_cast<int>(keyboard.size());
        for( int i=0; i<Nk; i++ ){
            umap.emplace( keyboard[i],i );
        }

        int sum = umap.at(word[0]);
        int Nw = static_cast<int>(word.size());
        for( int i=1; i<Nw; i++ ){ // [i-1],[i]
            sum += std::abs( umap.at(word[i]) - umap.at(word[i-1]) );
        }
        return sum;

    }
};




//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 1165 :end ~~~~\n" );
}
}//~
