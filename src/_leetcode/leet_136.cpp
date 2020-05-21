/*
 * ====================== leet_136.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 136. 只出现一次的数字
 */
#include "innLeet.h"


namespace leet_136 {//~


// 普通法，使用 set 来删除 重复元素
int singleNumber( std::vector<int>& nums ){

    std::unordered_set<int> sett {};
    for( const int i : nums ){
        // 消除成对的元素
        if( sett.erase(i)==0 ){  sett.insert( i ); }
    }
    return *sett.begin();
}


// 使用 异或^ 来消除 成对元素
int singleNumber_2( std::vector<int>& nums ){
    int out {};
    for( const int i : nums ){
        out ^= i;
    }
    return out;
}


class CCC{};


template< typename T >
void foo( T &v ){
    cout << "foo" << endl;
}





//=========================================================//
void main_(){

    std::vector<int> v { 4 };

    cout << singleNumber_2(v) << endl;

    int val = 5^3^5^5^5;

    cout << val << endl;

    //--------
    //CCC c {};
    //foo( c );

    


    
    

    debug::log( "\n~~~~ leet: 136 :end ~~~~\n" );
}
}//~
