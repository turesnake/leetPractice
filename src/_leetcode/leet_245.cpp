/*
 * ====================== leet_245.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.05.29
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 245. 最短单词距离 III
 */
#include "innLeet.h"
#include <stack>

#include "TreeNode1.h"


namespace leet_245 {//~


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


// word1,word2 如果值相同，就将指向连个 独立的单词
class S{

    int single( std::vector<std::string>& words, const std::string &word1 ){
        int N = static_cast<int>(words.size());
        std::vector<int> v {};//idx
        for( int i=0; i<N; i++ ){
            if( words.at(i)==word1 ){ 
                v.push_back(i);
            }
        }
        int minOff {INT_MAX};
        int Nv = static_cast<int>(v.size());
        for( int i=1; i<Nv; i++ ){// i-1, i
            minOff = std::min( minOff, v.at(i)-v.at(i-1) );
        }
        return minOff;
    }


public:


    int shortestWordDistance( std::vector<std::string>& words, std::string word1, std::string word2 ){

        if( word1==word2 ){ return single(words,word1); }
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



};





//=========================================================//
void main_(){

    std::vector<std::string> v { "a", "c" };

    //cout << shortestDistance( v, "c", "a" ) << endl;




    debug::log( "\n~~~~ leet: 245 :end ~~~~\n" );
}
}//~
