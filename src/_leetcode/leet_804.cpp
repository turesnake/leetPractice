/*
 * ====================== leet_804.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.07.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 804. 唯一摩尔斯密码词
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_804 {//~



//  97%  75%
class S{

    const std::vector<std::string> morses {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
        ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
        ".--","-..-","-.--","--.."
    };

public:
    // 单词列表words 的长度不会超过 100。
    // 每个单词 words[i]的长度范围为 [1, 12]。
    // 每个单词 words[i]只包含小写字母
    int uniqueMorseRepresentations( std::vector<std::string>& words ){


        std::unordered_set<std::string> uset {};
        for( const auto &s : words ){
            std::string ms {};
            for( char c : s ){
                ms += morses[c-'a'];
            }
            uset.insert(ms);// maybe
        }
        return uset.size();

    }
};




//=========================================================//
void main_(){




    debug::log( "\n~~~~ leet: 804 :end ~~~~\n" );
}
}//~
