#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace sys_doc
{
	const string doc_mao_pao_sort = "思路：从第一个数开始左往右，大数沉淀。再到下一个数，继续从左往右，大数沉淀。依次进行";
	const string doc_mao_pao_jiwei_sort = "思路：先从左往右,大数沉淀。再从右往左,小数上浮。依次进行";
	const string doc_selection_sort = "思路：i从0到len-1,j从i+1到len,找出num[j]<num[i],并且num[j]最小的那个与num[i]交换位置";
	const string doc_insertion_sort = "思路：对于未排序数据(右手抓到的牌)，在已排序序列(左手已经排好序的手牌)中从后向前扫描，找到相应位置并插入。";
	const string doc_insertion_dichotomy_sort = "思路：对于插入排序，如果比较操作的代价比交换操作大的话，可以采用二分查找法来减少比较操作的次数，我们称为二分插入排序";
	const string doc_insertion_shell_sort = "思路：希尔排序通过将比较的全部元素分为几个区域来提升插入排序的性能。这样可以让一个元素可以一次性地朝最终位置前进一大步。然后算法再取越来越小的步长进行排序，算法的最后一步就是普通的插入排序，但是到了这步，需排序的数据几乎是已排好的了（此时插入排序较快）。";
	const string doc_queen_func = "经典的皇后问题，即在一个n*n的棋盘上放n个皇后，使得这n个皇后无法互相攻击( 任意2个皇后不能处于同一行，同一列或是对角线上)，输出所有可能的摆放情况。";
}