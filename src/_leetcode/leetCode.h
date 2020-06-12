/*
 * ======================== leetCode.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2020.01.01
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#ifndef TPR_LEET_CODE_H
#define TPR_LEET_CODE_H

#include "pch.h"


/* 惯用技巧：
 * -----
 * <limits.h>
 * INT_MIN = -2147483648
 * INT_MAX =  2147483647
 * -----
 * 字符串转 int
 * int val = std::stoi("-123");
 * -----
 * int 转 string: std::to_string()
 * -----
 * 容器可以直接用 一对迭代器来初始化
 * -----
 * 判断奇偶性，(1)取模：val%2 (2)判断末尾: val&1
 * -----
 * 消除成对的元素方法[1]
 *     if( set.erase(i)==0 ){ set.insert( i ); }
 * 消除成对的元素方法[2]
 *     异或运算 a^b^b = a
 *     可以将一整组数据都 异或起来，最后成对的元素都会被自动 对消掉
 * 
 * 
 * =============== 需要复习的内容 =================
 * -- 15:  三数之和，很麻烦...
 * -- 69:  求平方根: 二分查找，牛顿法
 * -- 94:  二叉树中序遍历的 迭代实现
 * -- 160: 双指针轮回遍历链表法
 * -- 169: Boyer-Moore Algorithm 多数投票算法
 * -- 238: 前缀积分，后缀积
 * -- 328: 双链表收集元素，最后合并链表
 * -- 445: 双栈，反向组装链表节点
 * -- 974: 前缀和+模 计算区间和是否被整除 
 * -- 922: 特殊的双指针：奇偶指针
 * -- m22: 双指针 固定间距法
 * -- m64: -1- 借助 逻辑运算符的短路特性，实现条件判断。-2- 快速乘
 * -- m08_05: 俄国农民乘法
 * -- m59_1: 单调队列
 * 
 * =============== 排序 =================
 * 有些题表面上没啥特征，但用朴素法实现后成绩并不好看
 * 也许它在要求你实现更精准的排序
 * 
 * ------ 题：
 * - 977:
 * 
 * =============== 二分查找 =================
 * -1- 明确每次细分，需要剔除的是那一部分元素
 *     含糊的元素，则要保留到下一回合，继续检查
 * -2- 寻找左边界，还是右边界，要使用不同的 mid 计算法
 *     寻找左侧边界时，mid偏左
 *     寻找右侧边界时，mid偏右
 * 
 * ------ 题：
 * - 34:
 * - 35:
 * - 278:
 * - 1351:
 * 
 * =============== dp =================
 * 有些 dp 题思路比较奇特，记录于此
 * 
 * ------ 题：
 * - 221: 正方形判定
 * - 718:
 *    
 * =============== 单调栈 =================
 * stk内元素一定是有序的，递增或递减
 * 每次处理新元素，将其对比与 stk.top()
 * 分别针对 大于小于等于，进行三种方式的处理
 * 彻底遍历完所有元素后，再将栈内剩余元素，做一层处理
 * 
 * ------ 题：
 * - 84:
 * - 85: 基于84的升级版
 * - 496:
 * - 581:
 * - 739:
 * - 901:
 * 
 * =============== 双向遍历法 =================
 * ------ 题：
 * - 581:
 * 
 * =============== 并查集 =================
 * - [0]空置，[i]=i; 初始值指向自己，这样，每个元素互不联通
 * - find(a) 时，顺带执行 路径压缩，让 a 指向 root，加速后面的查找
 * - merge 操作时，改写的是 rootA 或 rootB
 * 
 * ------ 题：
 * - 990: 未完成
 * 
 * =============== 前缀和/积 =================
 * 并不容易想到的方法
 * ------ 题：
 * - 523：
 * - 560:
 */


namespace leet_1 { void main_(); }

namespace leet_3 { void main_(); }
namespace leet_4 { void main_(); }
namespace leet_5 { void main_(); }
namespace leet_6 { void main_(); }
namespace leet_7 { void main_(); }
namespace leet_8 { void main_(); }
namespace leet_9 { void main_(); }// 回文数，待新方案：8.02%, 5.95% 

namespace leet_11 { void main_(); }

namespace leet_13 { void main_(); }
namespace leet_14 { void main_(); }
namespace leet_15 { void main_(); }
namespace leet_16 { void main_(); }
namespace leet_17 { void main_(); }


namespace leet_20 { void main_(); }
namespace leet_21 { void main_(); }
namespace leet_22 { void main_(); }// 回溯
namespace leet_23 { void main_(); }
namespace leet_24 { void main_(); }

namespace leet_26 { void main_(); }
namespace leet_27 { void main_(); }

namespace leet_34 { void main_(); }
namespace leet_35 { void main_(); }// 二分查找 

namespace leet_39 { void main_(); }
namespace leet_42 { void main_(); }
namespace leet_43 { void main_(); }// 19.69% 40.74%
namespace leet_46 { void main_(); }
namespace leet_48 { void main_(); }// 矩阵

namespace leet_53 { void main_(); }//=*--动态规划--*=
namespace leet_54 { void main_(); }
namespace leet_56 { void main_(); }
namespace leet_58 { void main_(); }//...无脑...

namespace leet_62 { void main_(); }//=*--动态规划--*= 基础
namespace leet_63 { void main_(); }//=*--动态规划--*=
namespace leet_64 { void main_(); }//=*--动态规划--*=

namespace leet_66 { void main_(); }//...无脑...
namespace leet_67 { void main_(); }

namespace leet_69 { void main_(); }
namespace leet_70 { void main_(); }//=*--动态规划--*=
namespace leet_72 { void main_(); }
namespace leet_73 { void main_(); }

namespace leet_75 { void main_(); }
namespace leet_78 { void main_(); }

namespace leet_83 { void main_(); }
namespace leet_84 { void main_(); }
namespace leet_85 { void main_(); }

namespace leet_86 { void main_(); }
namespace leet_88 { void main_(); }

namespace leet_92 { void main_(); }
namespace leet_94 { void main_(); }
namespace leet_95 { void main_(); }//=*--动态规划--*=
namespace leet_96 { void main_(); }//=*--动态规划--*=

namespace leet_98 { void main_(); }

namespace leet_100 { void main_(); }
namespace leet_101 { void main_(); }
namespace leet_102 { void main_(); }

namespace leet_104 { void main_(); }
namespace leet_105 { void main_(); }
namespace leet_106 { void main_(); }
namespace leet_107 { void main_(); }
namespace leet_108 { void main_(); }
namespace leet_109 { void main_(); }
namespace leet_110 { void main_(); }
namespace leet_111 { void main_(); }
namespace leet_112 { void main_(); }

namespace leet_116 { void main_(); }

namespace leet_120 { void main_(); }//=*--动态规划--*=
namespace leet_121 { void main_(); }

namespace leet_124 { void main_(); }

namespace leet_128 { void main_(); }
namespace leet_129 { void main_(); }
namespace leet_130 { void main_(); }// 广度优先
namespace leet_136 { void main_(); }// 异或消除成对元素
namespace leet_138 { void main_(); }

namespace leet_141 { void main_(); }
namespace leet_143 { void main_(); }
namespace leet_144 { void main_(); }
namespace leet_145 { void main_(); }

namespace leet_148 { void main_(); }

namespace leet_155 { void main_(); }

namespace leet_160 { void main_(); }

namespace leet_167 { void main_(); }
namespace leet_169 { void main_(); }// Boyer-Moore Algorithm 多数投票算法

namespace leet_172 { void main_(); }
namespace leet_173 { void main_(); }

namespace leet_191 { void main_(); }//...无脑...

namespace leet_198 { void main_(); }//=*--动态规划--*=
namespace leet_200 { void main_(); }
namespace leet_202 { void main_(); }
namespace leet_203 { void main_(); }
namespace leet_204 { void main_(); }// 18.16%，84.62%

namespace leet_206 { void main_(); }

namespace leet_208 { void main_(); }
namespace leet_209 { void main_(); }

namespace leet_215 { void main_(); }
namespace leet_217 { void main_(); }

namespace leet_221 { void main_(); }
namespace leet_222 { void main_(); }
namespace leet_225 { void main_(); }//...无脑...
namespace leet_226 { void main_(); }

namespace leet_231 { void main_(); }//...无脑...
namespace leet_232 { void main_(); }

namespace leet_234 { void main_(); }
namespace leet_235 { void main_(); }
namespace leet_236 { void main_(); }
namespace leet_237 { void main_(); }
namespace leet_238 { void main_(); }

namespace leet_243 { void main_(); }
namespace leet_244 { void main_(); }
namespace leet_245 { void main_(); }


namespace leet_256 { void main_(); }//=*--动态规划--*=
namespace leet_257 { void main_(); }
namespace leet_258 { void main_(); }

namespace leet_263 { void main_(); }
namespace leet_264 { void main_(); }

namespace leet_270 { void main_(); }

namespace leet_278 { void main_(); }
namespace leet_279 { void main_(); }// bfs

namespace leet_281 { void main_(); }
namespace leet_283 { void main_(); }

namespace leet_287 { void main_(); }

namespace leet_293 { void main_(); }//...无脑...
namespace leet_295 { void main_(); }// 最大堆+最小堆 求中位数
namespace leet_297 { void main_(); }
namespace leet_298 { void main_(); }

namespace leet_300 { void main_(); }// **难**
namespace leet_303 { void main_(); }// 树状数组
namespace leet_307 { void main_(); }// 树状数组
namespace leet_314 { void main_(); }


namespace leet_328 { void main_(); }

namespace leet_338 { void main_(); }// 临时方案，等待更正式的方案

namespace leet_342 { void main_(); }// 二进制/位运算
namespace leet_344 { void main_(); }//...无脑...
namespace leet_346 { void main_(); }
namespace leet_347 { void main_(); }
namespace leet_349 { void main_(); }

namespace leet_357 { void main_(); }

namespace leet_369 { void main_(); }//...无脑...

namespace leet_371 { void main_(); }

namespace leet_374 { void main_(); }// 奇怪，与本机运行不一致...
namespace leet_375 { void main_(); }//=*--动态规划--*= **难**

namespace leet_401 { void main_(); }
namespace leet_402 { void main_(); }
namespace leet_407 { void main_(); }
namespace leet_409 { void main_(); }

namespace leet_414 { void main_(); }
namespace leet_415 { void main_(); }

namespace leet_421 { void main_(); }

namespace leet_429 { void main_(); }

namespace leet_445 { void main_(); }
namespace leet_449 { void main_(); }

namespace leet_451 { void main_(); }
namespace leet_452 { void main_(); }
namespace leet_455 { void main_(); }

namespace leet_461 { void main_(); }//...无脑...
namespace leet_464 { void main_(); }

namespace leet_474 { void main_(); }

namespace leet_486 { void main_(); }//=*--动态规划--*= 100%  100%

namespace leet_496 { void main_(); }

namespace leet_500 { void main_(); }//...无脑...
namespace leet_504 { void main_(); }
namespace leet_509 { void main_(); }

namespace leet_513 { void main_(); }
namespace leet_515 { void main_(); }// 27%, 25%

namespace leet_516 { void main_(); }//=*--动态规划--*= 5.34% 75% 

namespace leet_520 { void main_(); }//...无脑...
namespace leet_523 { void main_(); }// 前缀和

namespace leet_530 { void main_(); }

namespace leet_538 { void main_(); }// 倒置的 中序遍历 26% 7%

namespace leet_543 { void main_(); }
namespace leet_547 { void main_(); }// 并查集

namespace leet_557 { void main_(); }
namespace leet_559 { void main_(); }
namespace leet_560 { void main_(); }

namespace leet_563 { void main_(); }

namespace leet_572 { void main_(); }

namespace leet_581 { void main_(); }// 双向遍历法

namespace leet_589 { void main_(); }
namespace leet_590 { void main_(); }

namespace leet_617 { void main_(); }

namespace leet_633 { void main_(); }
namespace leet_637 { void main_(); }

namespace leet_647 { void main_(); }//=*--动态规划--*= // 27% 78%
namespace leet_648 { void main_(); }// 字典树

namespace leet_652 { void main_(); }// 序列化 5%
namespace leet_653 { void main_(); }
namespace leet_654 { void main_(); }// 5.13%, 7.69%

namespace leet_663 { void main_(); }

namespace leet_671 { void main_(); }

namespace leet_677 { void main_(); }// 字典树

namespace leet_684 { void main_(); }// 并查集
namespace leet_687 { void main_(); }

namespace leet_696 { void main_(); }
namespace leet_698 { void main_(); }

namespace leet_701 { void main_(); }
namespace leet_704 { void main_(); }
namespace leet_709 { void main_(); }//...无脑...

namespace leet_712 { void main_(); }//=*--动态规划--*= 5.28%  55.56%
namespace leet_713 { void main_(); }

namespace leet_718 { void main_(); }

namespace leet_720 { void main_(); }// 字典树
namespace leet_721 { void main_(); }// 并查集

namespace leet_739 { void main_(); }

namespace leet_763 { void main_(); }
namespace leet_766 { void main_(); }// 矩阵

namespace leet_771 { void main_(); }//...无脑...

namespace leet_783 { void main_(); }
namespace leet_784 { void main_(); }

namespace leet_814 { void main_(); }

namespace leet_821 { void main_(); }
namespace leet_876 { void main_(); }

namespace leet_889 { void main_(); }

namespace leet_897 { void main_(); }

namespace leet_905 { void main_(); }

namespace leet_912 { void main_(); }// sorts

namespace leet_922 { void main_(); }// 双指针：奇偶指针

namespace leet_931 { void main_(); }//=*--动态规划--*=

namespace leet_938 { void main_(); }

namespace leet_945 { void main_(); }

namespace leet_974 { void main_(); }
namespace leet_977 { void main_(); }

namespace leet_980 { void main_(); }

namespace leet_989 { void main_(); }
namespace leet_990 { void main_(); }

namespace leet_997 { void main_(); }// 5.12%, 16.67%
namespace leet_998 { void main_(); }

namespace leet_1022 { void main_(); }
namespace leet_1025 { void main_(); }//=*--动态规划--*=
namespace leet_1047 { void main_(); }
namespace leet_1064 { void main_(); }// 17.22%  33.33% 未来精进
namespace leet_1065 { void main_(); }// 字典树
namespace leet_1071 { void main_(); }

namespace leet_1085 { void main_(); }//...无脑...
namespace leet_1089 { void main_(); }

namespace leet_1104 { void main_(); }

namespace leet_1114 { void main_(); }// threads
namespace leet_1119 { void main_(); }//...无脑...

namespace leet_1130 { void main_(); }//=*--动态规划--*= 29.51%, 50%
namespace leet_1133 { void main_(); }

namespace leet_1143 { void main_(); }//=*--动态规划--*= 8.93%, 100%

namespace leet_1150 { void main_(); }
namespace leet_1160 { void main_(); }// 5.15% 20%

namespace leet_1180 { void main_(); }//...无脑...

namespace leet_1207 { void main_(); }//...无脑...

namespace leet_1214 { void main_(); }

namespace leet_1277 { void main_(); }//=*--动态规划--*= 5.07%， 50%

namespace leet_1281 { void main_(); }//...无脑...

namespace leet_1290 { void main_(); }

namespace leet_1302 { void main_(); }
namespace leet_1304 { void main_(); }//...无脑...
namespace leet_1305 { void main_(); }

namespace leet_1313 { void main_(); }//...无脑...
namespace leet_1314 { void main_(); }//=*--动态规划--*=
namespace leet_1315 { void main_(); }

namespace leet_1323 { void main_(); }//...无脑...
namespace leet_1325 { void main_(); }

namespace leet_1351 { void main_(); }

namespace leet_1365 { void main_(); }

namespace leet_1381 { void main_(); }
namespace leet_1382 { void main_(); }

namespace leet_1441 { void main_(); }
namespace leet_1457 { void main_(); }

namespace leet_1460 { void main_(); }//...无脑...
namespace leet_1464 { void main_(); }


namespace leet_LCP_01 { void main_(); }//...无脑...
namespace leet_LCP_06 { void main_(); }//...无脑...

namespace leet_m02_07 { void main_(); }
namespace leet_m03 { void main_(); }
namespace leet_m03_02 { void main_(); }
namespace leet_m05 { void main_(); }//...无脑...
namespace leet_m06 { void main_(); }
namespace leet_m07 { void main_(); }
namespace leet_m09 { void main_(); }// 用两栈实现队列，...无脑...
namespace leet_m15 { void main_(); }//...无脑...
namespace leet_m16_11 { void main_(); }
namespace leet_m22 { void main_(); }// 双指针固定间距法
namespace leet_m24 { void main_(); }
namespace leet_m25 { void main_(); }
namespace leet_m27 { void main_(); }
namespace leet_m28 { void main_(); }
namespace leet_m29 { void main_(); }
namespace leet_m39 { void main_(); }
namespace leet_m40 { void main_(); }
namespace leet_m42 { void main_(); }//=*--动态规划--*=
namespace leet_m46 { void main_(); }
namespace leet_m47 { void main_(); }//=*--动态规划--*=
namespace leet_m50 { void main_(); }//...无脑...
namespace leet_m53 { void main_(); }// 二分查找
namespace leet_m53_1 { void main_(); }
namespace leet_m57 { void main_(); }
namespace leet_m57_2 { void main_(); }
namespace leet_m58_1 { void main_(); }//...无脑...
namespace leet_m58_2 { void main_(); }//...无脑...
namespace leet_m62 { void main_(); }
namespace leet_m64 { void main_(); }

namespace leet_m01_1 { void main_(); }
namespace leet_m01_01 { void main_(); }//...无脑...
namespace leet_m01_06 { void main_(); }

namespace leet_m02_03 { void main_(); }

namespace leet_m03_04 { void main_(); }//...无脑...
namespace leet_m04_02 { void main_(); }
namespace leet_m04_03 { void main_(); }
namespace leet_m04_04 { void main_(); }

namespace leet_m08_05 { void main_(); }
namespace leet_m08_07 { void main_(); }

namespace leet_m10_01 { void main_(); }

namespace leet_m16_01 { void main_(); }
namespace leet_m16_07 { void main_(); }
namespace leet_m16_17 { void main_(); }//=*--动态规划--*= 34.46%，100%

namespace leet_m17_04 { void main_(); }
namespace leet_m17_10 { void main_(); }
namespace leet_m17_12 { void main_(); }
namespace leet_m17_16 { void main_(); }//=*--动态规划--*=

namespace leet_m32_1 { void main_(); }
namespace leet_m32_2 { void main_(); }

namespace leet_m37 { void main_(); }

namespace leet_m55_1 { void main_(); }
namespace leet_m56_1 { void main_(); }

namespace leet_m59_1 { void main_(); }// 单调队列 [罕见]

// oths:
namespace leet_knapsack_problems { void main_(); }// 背包问题练习


inline void leetCode_mian(){
    debug::log("\n\n============= Leet Code: Begin ================>>\n");


    leet_48::main_();


    debug::log("\n============= Leet Code: End ==================<<\n\n");
}


#endif 

