/*
 * ====================== leet_58.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.20
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 58. 最后一个单词的长度
 */
#include "innLeet.h"


namespace leet_58 {//~



int lengthOfLastWord( std::string s ){

    if( s.empty() ){ return 0; }
    bool isLstLetter {false};
    bool isFind  {false};
    int ridx {-1}; // 右侧idx
    int i=static_cast<int>(s.size())-1;
    for( ; i>=0; i-- ){// 倒序
        bool isNowLetter = s.at(i)!=' ';
        if( !isLstLetter && isNowLetter ){
            isFind = true; 
            ridx = i; 
        }else if( isLstLetter && !isNowLetter ){
            break;
        }
        isLstLetter = isNowLetter;
    }
    // 返回情况很复杂，要好好分析，但最后可以被合并
    return isFind ? (ridx-i) : 0; 
}



//=========================================================//
void main_(){

    cout << lengthOfLastWord( "asdwdvdv asdwd sdadwdk asdk" ) << endl;

    
    

    debug::log( "\n~~~~ leet: 58 :end ~~~~\n" );
}
}//~
