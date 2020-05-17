/*
 * ====================== leet_696.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.17
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 696. 计数二进制子串
 */
#include "innLeet.h"
#include "ListNode.h"


namespace leet_696 {//~




class S{
public:

    int countBinarySubstrings( std::string s ){

        if( s.empty() || s.size()==1 ){ return 0; }
        // 以下情况，一定有 2个或以上元素
        std::vector<int> lens {};
        int sSize = static_cast<int>(s.size());
        int count = 1;
        char lstC = s.at(0);
        for( int i=1; i<sSize; i++ ){
            char currentC = s.at(i);
            if( currentC != lstC ){ // 本元素进入 新的段落
                lstC = currentC;
                lens.push_back( count );
                count = 1;
            }else{
                count++;
            }
        }
        lens.push_back( count );// 补上最后一段
        // 现在，每一段的长度，都收集在 lens 中了
        if( lens.size()<=1 ){ return 0; }
        // 以下情况，lens 一定有 2个或以上元素
        int sum {0};
        for( int i=1; i<static_cast<int>(lens.size()); i++ ){
            int l = lens.at(i-1);
            int r = lens.at(i);
            sum += (l<=r) ? l : r;
        }
        return sum;
    }
};





//=========================================================//
void main_(){

    auto ret = S{}.countBinarySubstrings( "11111" );

    cout << "ret = " << ret << endl;

    

    debug::log( "\n~~~~ leet: 696 :end ~~~~\n" );
}
}//~

