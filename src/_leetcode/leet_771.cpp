/*
 * ====================== leet_771.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 771. 宝石与石头
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_771 {//~


// 13%, 100%
int numJewelsInStones( std::string J, std::string S) {

    std::unordered_map<char,int> umap {};
    for( char c : S ){
        auto [it,bl]=umap.emplace(c,1);
        if(!bl){ it->second++; }
    }
    int sum {0};
    for( char c : J ){
        if( umap.find(c)!=umap.end() ){
            sum += umap.at(c);
        }
    }
    return sum;
}



// 一种加速的办法是 用 vector(26*2,0) 来取代 umap
// 懒得实现了...



//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: 771 :end ~~~~\n" );
}
}//~
