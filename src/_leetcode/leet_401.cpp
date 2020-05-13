/*
 * ====================== leet_401.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.12
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 401. 二进制手表
 */
#include "innLeet.h"


namespace leet_401 {//~



// 检测目标数字，是否合法
void check_and_insert( std::vector<std::string> &strs_, const std::string &led_ ){

    assert( led_.size() == 10 );
    int hs {0};
    int ms {0};
    for( int i=0; i<10; i++ ){
        int v = led_.at(i)-'0';
        (i <= 3) ?
                hs = hs * 2 + v :
                ms = ms * 2 + v;
    }
    if( hs<=11 && ms<=59 ){
        std::string s = std::to_string( hs );
        s += ":";
        if( ms<=9 ){s += "0";}
        s += std::to_string( ms );
        strs_.push_back( s );
    }
}




void work(  std::vector<std::string> &strs_,
            std::string led_, 
            int ledI_,
            int num_,
            int totalNum_ ){

    if( num_ == 0 ){ // 灯加完了
        led_.insert( led_.end(), 10-static_cast<int>(led_.size()), '0' ); // 尾部补“0”
        check_and_insert( strs_, led_ );
        return;
    }
    if( (10-ledI_) == num_ ){ // 本灯，以及后面所有灯都要点亮
        led_.insert( led_.end(), num_, '1' ); // 唯一的方案，
        check_and_insert( strs_, led_ );
        return;
    }else{
        // 递归细分为更多 子可能性
        work( strs_, led_+"1", ledI_+1, num_-1, totalNum_ ); // 本灯亮
        work( strs_, led_+"0", ledI_+1, num_,   totalNum_ ); // 本灯不亮
    }
}




std::vector<std::string> readBinaryWatch( int num ) {

    std::vector<std::string> strs {};
    work( strs, "", 0, num, num );
    return strs;
}




//=========================================================//
void main_(){

    

    auto ret = readBinaryWatch( 8 );

    for( const auto &s : ret ){
        cout << s << endl;
    }

    

    debug::log( "\n~~~~ leet: 401 :end ~~~~\n" );
}
}//~
