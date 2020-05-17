/*
 * ====================== leet_1071.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1071. 字符串的最大公因子
 */
#include "innLeet.h"



namespace leet_1071 {//~


// 辗转相除法
int gcd_2( int a, int b ){
    if( a >= b ){
        int r = a%b;
        return (r==0) ? b : gcd_2(b,r);
    }else{
        int r = b%a;
        return (r==0) ? a : gcd_2(a,r);
    }
}


// gcd字符串，其长度也一定是 两个参数字符串 长度的 gcd
// 求的 gcdStr 长度后，就能获得 gcdStr 本体
// 然后就是 逐个字符比较，确保这个 gcdStr 是有效的，否则返回 ""
std::string gcdOfStrings( std::string str1, std::string str2 ){

    if( str1.empty() || str2.empty() ){ return ""; }
    if( str1 == str2 ){ return str1; }

    int len1 = static_cast<int>(str1.size());
    int len2 = static_cast<int>(str2.size());

    int gcdLen = gcd_2( len1, len2 );
    std::string gcdStr ( str1, 0, gcdLen ); // 目标字符串

    // 检测剩余段落是否都符合
    for( int i=0; i<len1; i++ ){
        if( str1.at(i) != gcdStr.at(i%gcdLen) ){
            return "";
        }
    }
    for( int i=0; i<len2; i++ ){
        if( str2.at(i) != gcdStr.at(i%gcdLen) ){
            return "";
        }
    }
    return gcdStr;
}





//=========================================================//
void main_(){

    cout << "gcdStr = " << gcdOfStrings( "ABCCBC", "ABC" ) << endl;

    debug::log( "\n~~~~ leet: 1071 :end ~~~~\n" );
}
}//~

