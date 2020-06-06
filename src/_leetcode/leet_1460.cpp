/*
 * ====================== leet_1460.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1460. 通过翻转子数组使两个数组相等
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1460 {//~


// 只要判断两 数组 元素相同即可 
class S{
public:
    // 1<= len <= 1000
    // 1<= [i] <= 1000
    bool canBeEqual( std::vector<int> target, std::vector<int> arr ){

        std::unordered_map<int,int> umap {}; //<val,num>
        for( int i : target ){
            auto [it,bl] = umap.emplace(i,1);
            if(!bl){ it->second++; }
        }
        for( int i : arr ){
            auto fit = umap.find(i);
            if( fit!=umap.end() ){
                fit->second--;
                if( fit->second==0 ){
                    umap.erase(i);
                }
            }else{
                return false;
            }
        }
        return umap.empty();
    }
};



//=========================================================//
void main_(){

    cout << S{}.canBeEqual( {1,2,3,4}, {2,4,1,3} )<<endl;

    
    debug::log( "\n~~~~ leet: 1460 :end ~~~~\n" );
}
}//~
