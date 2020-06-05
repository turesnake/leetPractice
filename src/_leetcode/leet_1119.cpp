/*
 * ====================== leet_1119.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.04
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1119. 删去字符串中的元音
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1119 {//~



class S{
    std::unordered_set<char> sett{ 'a','e','i','o','u' };
public:
    std::string removeVowels( std::string S ){
        std::string out {};
        for( char c : S ){
            if( sett.find(c)==sett.end() ){
                out.push_back(c);
            }
        }
        return out;
    }
};





//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 1119 :end ~~~~\n" );
}
}//~
