/*
 * ====================== leet_1441.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1441. 用栈操作构建数组
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1441 {//~


class S{
public:
    std::vector<std::string> buildArray(std::vector<int> target, int n) {

        int Nt = static_cast<int>(target.size());
        int ti = 0;// target idx

        std::vector<std::string> strs {};

        for( int i=1; i<=n && ti<Nt; i++ ){
            if( i < target.at(ti) ){
                strs.push_back("Push");
                strs.push_back("Pop");
            }else if( i == target.at(ti) ){
                strs.push_back("Push");
                ti++;
            }
        }
        return strs;
    }
};



//=========================================================//
void main_(){

    auto ret = S{}.buildArray( {1,3}, 3 );

    for( auto &s : ret ){
        cout<<s<<endl;
    }
    

    debug::log( "\n~~~~ leet: 1441 :end ~~~~\n" );
}
}//~
