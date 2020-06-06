/*
 * ====================== leet_1207.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1207. 独一无二的出现次数
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1207 {//~


// 朴素法，88%, 100%
class S{
public:
    // 1<= ken <= 1000
    bool uniqueOccurrences( std::vector<int>& arr ){

        std::unordered_map<int,int> umap {};//<val,num>
        std::unordered_set<int> sett {};
        for( int i : arr ){
            umap[i]++;
        }
        for( auto [val,num] : umap ){
            if( sett.count(num)>0 ){ return false; }
            sett.insert(num);
        }
        return true;
    }
};


//=========================================================//
void main_(){

    
    debug::log( "\n~~~~ leet: 1207 :end ~~~~\n" );
}
}//~
