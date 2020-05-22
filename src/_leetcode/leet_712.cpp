/*
 * ====================== leet_712.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.21
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 712. 两个字符串的最小ASCII删除和
 */
#include "innLeet.h"


namespace leet_712 {//~




// 动态规划 5.28%  55.56%
// 参数 字符串不为空，都为小写字母
//
// 看起来像是没有用到 更好的 设计思路
//
int minimumDeleteSum( std::string s1, std::string s2 ){

    int H = static_cast<int>(s2.size());// 放置在纵坐标 h
    int W = static_cast<int>(s1.size());// 放置在横坐标 w
    std::vector<std::vector<int>> dp (H+1, std::vector<int>(W+1));
        // 右侧和下方 各多处一排
    // 手动生成一部分 技术值
    for( int w=1; w<W+1; w++ ){
        dp.at(0).at(w) = dp.at(0).at(w-1) + static_cast<int>(s1.at(w-1)); 
    }
    for( int h=1; h<H+1; h++ ){
        dp.at(h).at(0) = dp.at(h-1).at(0) + static_cast<int>(s2.at(h-1));
    }
    // 生成剩余数据
    for( int h=1; h<H+1; h++ ){
        for( int w=1; w<W+1; w++ ){
            if( s1.at(w-1) == s2.at(h-1) ){// h-1, w-1 这两个字母是相同的
                dp.at(h).at(w) = dp.at(h-1).at(w-1);
            }else{
                dp.at(h).at(w) = std::min(
                    dp.at(h).at(w-1) + static_cast<int>(s1.at(w-1)),// 左侧格子
                    dp.at(h-1).at(w) + static_cast<int>(s2.at(h-1)) // 上方格子
                );
            }
        }
    }
    /*
    for( auto &c : dp ){
        for( auto &it : c ){ cout << it << ",  "; }
        cout << endl;
    }
    cout << "========" << endl;
    */
    return dp.back().back();
}






//=========================================================//
void main_(){

    
    cout << minimumDeleteSum( "delete", "leet" ) << endl;
    //cout << minimumDeleteSum( "a", "at" ) << endl;


    debug::log( "\n~~~~ leet: 712 :end ~~~~\n" );
}
}//~
