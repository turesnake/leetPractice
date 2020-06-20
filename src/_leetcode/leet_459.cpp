/*
 * ====================== leet_459.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 459. 重复的子字符串
 */
#include "innLeet.h"


namespace leet_459 {//~


// 先假设字符串符合要求，那么
// -1- 总字符串的 首字母/尾字母，也是 目标子串 的首字母/尾字母 
// -2- 子串长度 要能被 总长度整除



class S{
public:

    // 官网解法 -1-
    // ----
    // s+s 是一个惯用技术。如果 s 是 重复子串，那么它一定 n 个子串组成
    // 在 s+s 中，查找 第二个 s，找到的 下标，就是 子串的 下标
    // 如果 s 确实是 重复子串，那么 上面查找到的下标，就应在 小于 s的长度
    //======
    // 1<= len <= 10000
    bool repeatedSubstringPattern_1( std::string s ){
        std::string twoS {s+s};
        return twoS.find(s,1) != s.size();
    }


    // 还有一个类似的思路: 减去 s+s 的 头尾字母
    // 然后查找，剩余的字符串中，是否存在 s
    bool repeatedSubstringPattern_2( std::string s ){
        std::string twoS ( s, 1, s.size()-1 ); // 去头字母
        twoS += s;
        twoS.pop_back();// 去尾字母
        return twoS.find(s) != std::string::npos;
    }
};




//=========================================================//
void main_(){

    

    
    debug::log( "\n~~~~ leet: 459 :end ~~~~\n" );
}
}//~
