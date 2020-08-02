/*
 * ====================== leet_1361.cpp ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.08.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 * 1361. 验证二叉树
 */
#include "innLeet.h"
#include "TreeNode1.h"


namespace leet_1361 {//~


// -1- 边数等于 n-1
// -2- 只有一个 连通分量 


// 并查集   56%   62%
class S{

class UnionFindSet{
    std::vector<int> st {};
    int N {};
    int find( int a ){
        if( st[a]==a ){ return a; }
        st[a] = find(st[a]);
        return st[a];
    }
public:
    explicit UnionFindSet( int N_ ):N(N_){
        st.resize(N,0);
        for( int i=0; i<N; i++ ){
            st[i]=i;
        }
    }
    void merge( int a, int b ){
        int ra = find(a);
        int rb = find(b);
        if( ra==rb ){ return; }
        st[rb]=ra;
    }
    bool isSameRoot( int a, int b ){
        return find(a)==find(b);
    }
    int rootSize(){
        int sum = 0;
        for( int i=0; i<N; i++ ){
            if( st[i]==i ){ sum++; }
        }
        return sum;
    }
};

public:
    // 1 <= n <= 10^4
    // leftChild.length == rightChild.length == n
    // -1 <= leftChild[i], rightChild[i] <= n - 1
    bool validateBinaryTreeNodes( int n, std::vector<int>& leftChild, std::vector<int>& rightChild ){

        UnionFindSet ufs {n};
        for( int i=0; i<n; i++ ){
            int l = leftChild[i];
            int r= rightChild[i];
            if( l>-1 ){
                if( ufs.isSameRoot(i,l) ){ return false; }
                ufs.merge(i,l);
            }
            if( r>-1 ){
                if( ufs.isSameRoot(i,r) ){ return false; }
                ufs.merge(i,r);
            }
        }
        return ufs.rootSize()==1;

    }
};



//=========================================================//
void main_(){

    
    

    debug::log( "\n~~~~ leet: 1361 :end ~~~~\n" );
}
}//~
