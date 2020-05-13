/*
 * ====================== leet_20.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 有效的括号 
 */
#include "innLeet.h"


namespace leet_20 {//~



bool isValid( std::string s) {

    if( s.empty() ){ return true; }
    std::deque<char> stack {};

    for( auto it=s.begin(); it!=s.end(); it++ ){
        char c = *it;
        switch ( c ){
            case '(':
            case '[':
            case '{':
                stack.push_back( c );
                break;
            case ')':
                if( stack.empty() || stack.back()!='(' ){ return false; } // Invalid
                stack.pop_back();
                break;
            case ']':
                if( stack.empty() || stack.back()!='[' ){ return false; } // Invalid
                stack.pop_back();
                break;
            case '}':
                if( stack.empty() || stack.back()!='{' ){ return false; } // Invalid
                stack.pop_back();
                break;
            default:
                return false; // Invalid
                break;
        }
    }
    return stack.empty();
}

// 鸡贼法
bool isValid_2( std::string s) {

    if( s.empty() ){ return true; }
    std::deque<char> stack {};

    for( auto it=s.begin(); it!=s.end(); it++ ){
        char c = *it;
        switch ( c ){
            case '(': stack.push_back( ')' ); break;
            case '[': stack.push_back( ']' ); break;
            case '{': stack.push_back( '}' ); break;
            case ')':
            case ']':
            case '}':
                if( stack.empty() || stack.back()!=c ){ return false; } // Invalid
                stack.pop_back();
                break;
            default:
                return false; // Invalid
                break;
        }
    }
    return stack.empty();
}





//=========================================================//
void main_(){

    std::vector<std::string> strs {
        "",
        "(",
        "()",
        "(){}[]",
        "(]",
        "([)]",
        "{[]}"
    };

    for( const auto &s : strs ){
        auto ret = isValid_2( s );
        debug::log("  \"{}\":{}",s,ret);
    }




    debug::log( "\n~~~~ leet: 20 :end ~~~~\n" );
}
}//~
