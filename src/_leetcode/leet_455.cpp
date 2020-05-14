/*
 * ====================== leet_455.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 455. 分发饼干
 */
#include "innLeet.h"


namespace leet_455 {//~


// 用最小堆来管理
int findContentChildren( std::vector<int>& g, std::vector<int>& s) {

    if( g.empty() || s.empty() ){ return 0; }
    std::priority_queue<int, std::vector<int>, std::greater<int>> 
        childs ( std::greater<int>{}, std::move(g) ); 
    std::priority_queue<int, std::vector<int>, std::greater<int>> 
        cooks ( std::greater<int>{}, std::move(s) );

    int out {0};
    for( ; !(childs.empty()||cooks.empty()); childs.pop(),cooks.pop(),out++ ){
        while( cooks.top() < childs.top() ){
            cooks.pop();
            if( cooks.empty() ){
                return out;
            }
        }
    }
    return out;
}


// vector原地排序，同时通过 尾端pop 的方式来管理
int findContentChildren_2( std::vector<int>& g, std::vector<int>& s) {

    if( g.empty() || s.empty() ){ return 0; }
    std::sort( g.begin(), g.end(), std::greater<int>{} );
    std::sort( s.begin(), s.end(), std::greater<int>{} );
    int out {0};

    for( ; !(g.empty()||s.empty()); g.pop_back(),s.pop_back(),out++ ){
        while( s.back() < g.back() ){
            s.pop_back();
            while( s.empty() ){
                return out;
            }
        }
    }
    return out;
}


// vector原地排序，用指针来遍历
// 和第二种在性能上没太大区别
int findContentChildren_3( std::vector<int>& g, std::vector<int>& s) {

    if( g.empty() || s.empty() ){ return 0; }
    std::sort( g.begin(), g.end() );
    std::sort( s.begin(), s.end() );

    auto gi = g.begin();
    auto si = s.begin();
    int out {0};
    for( ; gi!=g.end()&&si!=s.end(); gi++,si++,out++ ){
        while( *si < *gi ){
            si++;
            if( si==s.end() ){
                return out;
            }
        }
    }
    return out;
}




//=========================================================//
void main_(){
    
    std::vector<int> g { 1,2 };
    std::vector<int> s { 1,2,3 };
    auto ret = findContentChildren_3( g, s );

    cout << "ret = " << ret << endl;
    
    


    debug::log( "\n~~~~ leet: 455 :end ~~~~\n" );
}
}//~
