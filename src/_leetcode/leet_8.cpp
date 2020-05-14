/*
 * ====================== leet_8.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 8. 字符串转换整数 (atoi)
 */
#include "innLeet.h"


namespace leet_8 {//~



// 原始版，很简陋
int myAtoi( std::string str) {

    if( str.empty() ){ return 0; }

    int  out {0};
    bool isFindFstNum {false};
    bool isNegative {false};
    int idx {0};
    char c {0};

    int strSize = static_cast<int>(str.size());

    // find fst char
    for( ; idx<strSize; idx++ ){
        c = str.at(idx);
        if( c>='0' && c<='9' ){
            // find
            isFindFstNum = true;
            break;
        }else if( c == ' '  ){
            continue;
        }else if( (c=='+') || (c=='-') ){
            
            isNegative = c=='-';
            idx++;

            if( idx>=strSize ){ return 0; } // Invalid

            c = str.at(idx);

            if( c>='0' && c<='9'  ){
                // find
                isFindFstNum = true;
                break;
            }else{
                return 0; // Invalid
            }

        }else{
            return 0; // Invalid
        }
    }

    // 
    if( !isFindFstNum ){
        return 0; // Invalid
    }

    int mmin = INT_MIN/10;
    int mmax = INT_MAX/10;

    // calc num
    for( ; idx< static_cast<int>(str.size()); idx++ ){
        c = str.at(idx);
        if( !(c>='0' && c<='9') ){
            break;
        }

        int tempc = static_cast<int>(c-'0');
        if( isNegative ){// -
            if( (out < mmin) ||
                (out==mmin && tempc>8) ){
                return INT_MIN; // - overflow
            }
            out = out*10 - tempc;

        }else{// +
            if( (out > mmax) ||
                (out==mmax && tempc>7) ){
                return INT_MAX; // + overflow
            }
            out = out*10 + tempc;
        }
    }
    return out;
}



// 下次该用 状态机...
int myAtoi_2( std::string str) {


    return 0;
}



//=========================================================//
void main_(){

    std::vector<std::string> strs {
        "",
        "+",
        "-",
        " ",
        "    ",
        "  233",
        "42",
        "+42",
        "-42",
        "+ 42",
        "- 42",
        "     -42",
        "4193 with words",
        "words and 987",
        "87667127312382139123",
        "-91283472332",
        "2147483647",
        "-2147483648"
    };


    for( const auto &s : strs ){

        auto ret = myAtoi(s);
        debug::log( "\"{}\" :{}", s, ret );
    }
    


    debug::log( "\n~~~~ leet: 8 :end ~~~~\n" );
}
}//~
