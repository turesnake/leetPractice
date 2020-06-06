/*
 * ====================== leet_1089.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.06
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1089. 复写零
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_1089 {//~


// 90%, 12%
class S{
public:
    // 1 <= arr.length <= 10000
    // 0 <= arr[i] <= 9
    void duplicateZeros( std::vector<int>& arr ){

        int N = static_cast<int>(arr.size());
        int count = 1;
        int idx = 0;
        bool isInSecZero = false;// 在退出时，是否正指向 额外的0
        for( ; idx<N; idx++ ){
            if( count==N ){ break; }
            count++;
            if( arr.at(idx)==0 ){// 遇0要 额外行动一次
                if( count==N ){ 
                    isInSecZero = true;
                    break; 
                }
                count++;
            }
        }
        int ridx = N-1;
        // 手动调整尾部特殊情况
        if( arr.at(idx)==0 && !isInSecZero ){
            arr.at(ridx--) = 0;//只需要补 left 0
            idx--;
        }
        // 倒着 装填元素
        while( idx>=0 ){
            int v = arr.at(idx--);
            arr.at(ridx--) = v;
            if( v==0 ){// 额外装填一次0
                arr.at(ridx--) = 0;
            }
        }        
    }
};




//=========================================================//
void main_(){

    //std::vector<int> v { 1,0,2,3,0,4,5,0 };
    std::vector<int> v { 1,0,2,3,0,4 };


    S{}.duplicateZeros(v);

    for( int i : v ){
        cout<<i<<", ";
    }cout<<endl;



    
    debug::log( "\n~~~~ leet: 1089 :end ~~~~\n" );
}
}//~
