/*
 * ====================== leet_421.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.06.10
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 
 */
#include "innLeet.h"
#include "TreeNode1.h"
#include "ListNode.h"


namespace leet_421 {//~




// 做leetcode以来，写过的最长的一个... 一定是 思路上出了问题 



// 字典树
class S{
// 在这个实现中，所有 leaf 都在最后一层
// 不用设置 flag 了
struct TrieNode{
    TrieNode( char val_ ):val(val_){};
    TrieNode *son_0 {nullptr};
    TrieNode *son_1 {nullptr};
    char    val {}; // 1/0
};

    TrieNode *trie {nullptr};
    int outNum {};
    int bitDeep {0};// 最大值 占多少位 
    std::vector<char> bitVec {};
    std::vector<char> tmpAns {};
    

    // 值的高位，将被存储到 树的 顶部
    void insert( int val ){
        // 将 bit 值，顺序写入 vec
        bitVec.clear();
        bitVec.resize( bitDeep, 0 );
        for( int i=bitDeep-1,v=val; i>=0 && v>0; i--,v>>=1 ){
            bitVec.at(i) = static_cast<char>(v&1);
        }
        //--//
        TrieNode *p = trie;
        for( int i=0; i<bitDeep; i++ ){
            if( (bitVec.at(i)&1)==0 ){// 0
                if(!p->son_0){ p->son_0 = new TrieNode(0); }
                p = p->son_0;
            }else{// 1
                if(!p->son_1){ p->son_1 = new TrieNode(1); }
                p = p->son_1;
            }
        }
    }

    // 遍历 trie
    // a 可以为空，但 b 必不为空
    // a/b 都可表示 0/1
    // 如果 a/b 某个非空，那个它至少有一个 son
    void search( TrieNode *a, TrieNode *b, int deep ){

        if(!a){
            tmpAns.push_back(0); // 只有一条路，同值的
            if( deep == bitDeep ){
                check();
                tmpAns.pop_back();
                return;
            }
            TrieNode *b0 = b->son_0;
            TrieNode *b1 = b->son_1;

            if( b0 && b1 ){
                search( b0, b1, deep+1);
            }else{
                if(b0){ search(nullptr, b0, deep+1); }
                if(b1){ search(nullptr, b1, deep+1); }
            }
            tmpAns.pop_back();
        }else{
            tmpAns.push_back( a->val^b->val );
            if( deep == bitDeep ){
                check();
                tmpAns.pop_back();
                return;
            }
            TrieNode *a0 = a->son_0;
            TrieNode *a1 = a->son_1;
            TrieNode *b0 = b->son_0;
            TrieNode *b1 = b->son_1;
            if( a0 && a1 ){
                if( b0 && b1 ){
                    search( a0, b1, deep+1 );
                    search( a1, b0, deep+1 );
                }else if( !b0 && b1 ){
                    search( a0, b1, deep+1 );
                }else{// b0 && !b1
                    search( a1, b0, deep+1 );
                }
            }else if( !a0 && a1 ){
                if( b0 && b1 ){
                    search( a1, b0, deep+1 );
                }else if( !b0 && b1 ){
                    search( a1, b1, deep+1 );
                }else{// b0 && !b1
                    search( a1, b0, deep+1 );
                }
            }else{// a0 && !a1
                if( b0 && b1 ){
                    search( a0, b1, deep+1 );
                }else if( !b0 && b1 ){
                    search( a0, b1, deep+1 );
                }else{// b0 && !b1
                    search( a0, b0, deep+1 );
                }
            }
            tmpAns.pop_back();
        }
    }


    // 清算 
    void check(){
        int v = 0;
        for( int i=0; i<bitDeep; i++ ){
            v = 2*v + static_cast<int>(tmpAns.at(i));
        }
        outNum = std::max( outNum, v );        
    }

public:
    // 非空
    // 0<= [i] <= 2^31 正
    int findMaximumXOR( std::vector<int>& nums ){

        if( nums.size()==1 ){ return 0; }
        // 计算 最大深度 
        bool isHaveZero = false;
        int mmax = 0;
        for( int i : nums ){ 
            if( i>mmax ){ mmax=i; } 
            if( !isHaveZero && i==0 ){ isHaveZero = true; }
        }
        for( int v=mmax; v>0; v>>=1,bitDeep++ ){}

        trie = new TrieNode(0);
        for( int i : nums ){
            insert(i);
        }

        if( !trie->son_0 && !trie->son_1 ){
            return 0;
        }else if( trie->son_0 ){
            search( trie->son_1, trie->son_0, 1 );
        }else{
            search( trie->son_0, trie->son_1, 1 );
        }
        // 0 和 任何值异或，都为本值
        return isHaveZero ? std::max(outNum,mmax) : outNum;
    }
};





//=========================================================//
void main_(){

    //std::vector<int> v { 3,10,5,25,2,8 };
    //std::vector<int> v { 4,6,7 };

    std::vector<int> v { 32,18,33,42,29,20,26,36,15,46 };


    cout<<"ret: \n" <<S{}.findMaximumXOR(v)<<endl;


    
    debug::log( "\n~~~~ leet: 421 :end ~~~~\n" );
}
}//~
