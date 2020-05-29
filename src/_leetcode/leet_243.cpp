/*
 * ====================== leet_243.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 243. 最短单词距离
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_243 {//~


// 数组一定不为空，word1,word2 一定在 数组中
int shortestDistance( std::vector<std::string>& words, std::string word1, std::string word2) {

    int N = static_cast<int>(words.size());
    std::vector<std::pair<int,int>> v {};//<idx,1/2>
    for( int i=0; i<N; i++ ){
        if( words.at(i)==word1 ){ 
            v.emplace_back(i,1); 
        }else if( words.at(i)==word2 ){
            v.emplace_back(i,2); 
        }
    }
    int minOff {INT_MAX};
    int Nv = static_cast<int>(v.size());
    for( int i=1; i<Nv; i++ ){// i-1, i
        if( v.at(i-1).second != v.at(i).second ){
            minOff = std::min( minOff, v.at(i).first-v.at(i-1).first );
        }
    }
    return minOff;
}



//=========================================================//
void main_(){

    std::vector<std::string> v { "a", "c" };


    cout << shortestDistance( v, "c", "a" ) << endl;




    debug::log( "\n~~~~ leet: 243 :end ~~~~\n" );
}
}//~
