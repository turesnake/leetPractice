/*
 * ====================== leet_1160.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1160. 拼写单词
 */
#include "innLeet.h"


namespace leet_1160 {//~


// 5.15% 20%
class S{
public:

    int countCharacters( std::vector<std::string>& words, std::string chars ){

        if( words.empty() || chars.empty() ){ return 0; }
        
        std::vector<int> letters ( 26, 0 ); // 26字母 char-nums
        // 所及所有 可用字母，及其可用个数
        for( const char c : chars ){
            letters.at(c-'a')++;
        }

        std::unordered_map<char,int> wd {};// each word <char,nums>
        int sum {0};
        for( const auto &str : words ){
            wd.clear();
            for( const char c : str ){
                auto [it,bl] = wd.emplace( c, 1 ); // maybe
                if( !bl ){ it->second++; }
            }
            bool isLegel {true};
            for( auto [c,num] : wd ){
                if( wd.at(c) > letters.at(c-'a') ){
                    isLegel = false;
                    break;
                }
            }
            if( isLegel ){ sum += static_cast<int>(str.size()); }
        }
        return sum;
    }

};





//=========================================================//
void main_(){

    std::vector<std::string> v { "hello","world","leetcode" };
    std::string chars { "welldonehoneyr" };

    auto ret = S{}.countCharacters( v, chars );
    
    cout << "ret = " << ret << endl;


    debug::log( "\n~~~~ leet: 1160 :end ~~~~\n" );
}
}//~
