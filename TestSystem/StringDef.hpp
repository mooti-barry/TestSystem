#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace sys_doc
{
	const string doc_mao_pao_sort = "思路：从第一个数开始左往右，大数沉淀。再到下一个数，继续从左往右，大数沉淀。依次进行";
	const string doc_mao_pao_jiwei_sort = "思路：先从左往右,大数沉淀。再从右往左,小数上浮。依次进行";
	const string doc_selection_sort = "思路：i从0到len-1,j从i+1到len,找出num[j]<num[i],并且num[j]最小的那个与num[i]交换位置";
	const string doc_insertsion_sort = "思路：对于未排序数据(右手抓到的牌)，在已排序序列(左手已经排好序的手牌)中从后向前扫描，找到相应位置并插入。";
}