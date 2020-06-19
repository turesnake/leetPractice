/*
 * ====================== leet_125.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.18
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 125. 验证回文串
 */
#include "innLeet.h"


namespace leet_125 {//~

// 直接用 双指针 判断



//   85%  100%
class S{

    bool isLegel( char c ){
        return  (c>='0' && c<='9') || 
                (c>='a' && c<='z') ||
                (c>='A' && c<='Z');
    }

public:
    bool isPalindrome( std::string s ){

        if(s.empty()){ return true; }

        size_t N = s.size();
        size_t l = 0;
        size_t r = N-1;

        for(; l<r; l++,r-- ){
            
            for(; l<r && !isLegel(s[l]); l++ ){}// find l
            for(; l<r && !isLegel(s[r]); r-- ){}// find r
            if( l>=r ){ break; }

            if( s[l]>='A' && s[l]<='Z' ){ s[l] += 32; }// to sml
            if( s[r]>='A' && s[r]<='Z' ){ s[r] += 32; }// to sml

            if( s[l] != s[r] ){ return false; }
        }
        return true;
    }
};





//=========================================================//
void main_(){


    
    debug::log( "\n~~~~ leet: 125 :end ~~~~\n" );
}
}//~
