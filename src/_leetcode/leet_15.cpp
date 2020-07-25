/*
 * ====================== leet_15.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.04.14
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 15. 三数之和
 */
#include "innLeet.h"


namespace leet_15 {//~



// 这题甚至比很多困难题都麻烦 ...


// 2020_0617   11%   7%
// 先将数组排序，然后从头到尾地遍历，此为a
// 每一次针对剩余区间，分别用两指针指向 区间头尾，相向而行
// 查找合格的 b 和 c
// ---
// 此题的难点在于 重复元素的排除
// a/b/c 在遍历时，都要排除重复值 
// ---
// 优化：当 a大于0时，bc一定也大于0，可以终止判断

class S4{
public:
    std::vector<std::vector<int>> threeSum( std::vector<int>& nums) {

        if( nums.size()<3 ){ return {}; }

        std::sort( nums.begin(), nums.end() );
        int N = static_cast<int>(nums.size());

        std::vector<std::vector<int>> outs {};

        int  lstA = 0;
        for( int i=0; i<N-2; i++ ){
            int a = nums.at(i);

            if( a>0 ){ break; }// 核心优化项!!!
   
            if( i==0 ){
                lstA = a;
            }else{
                if( lstA == a ){ continue; } // 跳过重复的 a
                lstA = a;
            }

            //---//
            // 执行两数判断 b也要避免重复数
            int bcSum = 0 - a;

            bool isFst = true;
            int lstB = 0;
            int lstC = 0;
            int l = i+1;
            int r = N-1;
            while( l<r ){
                int b = nums.at(l);
                int c = nums.at(r);
                bool isL = false;
                bool isR = false;

                if( isFst ){
                    isFst = false;
                    lstB = b;
                    lstC = c;
                }

                int tmpSum = b + c;
                if( tmpSum < bcSum ){
                    isL = true;
                }else if( tmpSum > bcSum ){
                    isR = true;
                }else{// ==
                    outs.push_back({ a,b,c });
                    isL = true;
                    isR = true;
                }

                if( isL ){
                    l++;
                    for(; l<r && nums.at(l)==lstB; l++ ){}//排除重复数
                    lstB = nums.at(l);
                }
                if( isR ){
                    r--;
                    for(; l<r && nums.at(r)==lstC; r-- ){}//排除重复数
                    lstC = nums.at(r);
                }
            }
        }
        return outs;


    }
};



//=========================================================//
void main_(){

    std::vector<int> v { -5,-4,-4,-3,-3,-2,-2,-1,6,6,7,8,8,9 };

    //std::vector<int> v { -1, 0, 1, 2 };
    //std::vector<int> v { 1,2,-2,-1 };
    //std::vector<int> v { -1,0,1,2,-1,-4, 7, -2, -5, -4, -3, 0, 0, 0 };
    //std::vector<int> v { 0, 0, 0 };
    //std::vector<int> v { -1, -3, 5 };

    //std::vector<int> v { -1, 0 };


    //std::vector<int> v { -1,0,1,2,-1,-4, 7, -2, -5, -4, -3 };

    //std::vector<int> v { -1,0,1,2,-1,-4 };

    //auto retVecs = threeSum( v );
    auto retVecs = S4{}.threeSum( v );

    cout << "call DONE" << endl;

    for( const auto &iVec : retVecs ){
        debug::log("--------");
        cout << "   ";

        for( const auto i: iVec ){
            cout << i << ", ";
        }
        cout << endl;
    }

    


    debug::log( "\n~~~~ leet: 15 :end ~~~~\n" );
}
}//~
