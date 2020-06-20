/*
 * ====================== leet_1044.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1044. 最长重复子串
 */
#include "innLeet.h"


namespace leet_1044 {//~



// 判定一个 子字符串 是不是 重复子串
// parent.rfind(son); 获得 子串 在总字符串中，最后一个的位置
// 只要不等于 第一个，就说明存在重复



// 在题目思路上， 这题只是 1062 的 修改版
// 但是如果直接使用 1062 的暴力法，会超时.....

// 推荐学习并使用 Rabin-Karp 字符串编码术

// 二分查找 + 字符串hash：Rabin-Karp


class S{
public:
    // 2 <= S.lenh <= 10^5
    // 小写字母 
    std::string longestDupSubstring( std::string S ){


        int N = static_cast<int>(S.size());
        if(N==2){ return S[0]==S[1] ? std::string{S[0]} : ""; }

        



      
    }
};


//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 1044 :end ~~~~\n" );
}
}//~
