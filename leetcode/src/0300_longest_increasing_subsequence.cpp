/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

/*
	题目：
		给定一个无序的整数数组，找到其中最长上升子序列的长度。

	示例:
		输入: [10,9,2,5,3,7,101,18]
		输出: 4 
	解释: 
		最长的上升子序列是 [2,3,7,101]，它的长度是 4。
	
	说明:	
		可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
		你算法的时间复杂度应该为 O(n2) 。
	
	进阶: 
		你能将算法的时间复杂度降低到 O(n log n) 吗?

*/

#include <iostream>
#include <vector>

using namespace std;

// O(n^2)
void solution_1(vector<int> &array)
{
	if (array.size() == 0)
		return;
	
	// 记录对应位置的 序列长度，初始化为 1，因为至少包含自己 
	vector<int> lis(array.size());
	vector<vector<int> > lis_array(array.size()); 	
	for (int i=0; i<array.size(); i++) {
		lis[i] = 1;
		vector<int> temp;
		temp.push_back(array[i]);
		lis_array[i] = temp;
	}
	// 遍历每个元素 
	for (int i=0; i<array.size(); i++) {
		for (int j=0; j<i; j++) {
			// 基于第 i 个元素前边已经算出排序数量的
			// 找出与当前元素组成排序的最大排序数 
			if (array[j] < array[i]) {
				/*
				lis[i] = max(lis[i], lis[j]+1);
				*/
				
				if (lis[i] < lis[j]+1) {
					lis_array[i].clear();
					lis_array[i] = lis_array[j];
					lis_array[i].push_back(array[i]);
					lis[i] = lis[j]+1;
				}
				
			}
		}
	}
	
	int index = 1;
	for (int i=0; i<array.size(); i++) {
		if (lis[i] > lis[index])
			index = i;
	}
	
	cout << "max lis: " << lis[index] << endl;
	cout << "sequence:\n";
	
	for (int i=0; i<lis_array[index].size(); i++) {
		cout << lis_array[index][i] << ' ';
	}
	
	cout << endl;
}


// O(nlogn)
void solution_2(vector<int> &array)
{
    /*
        example: 3, 2, 5, 9, 1, 10, 7
        该方法是在进行一种覆盖操作，后续较小的数虽然会覆盖前边的数
        但是最大数并没有改变，且覆盖并不改变序列的长度和最大数
        那么这个序列的长度仍然表示开始那个较长的那个序列
        直到全部被覆盖掉
        3 -> 2 -> 2, 5 -> 2, 5, 9 -> 1, 5, 9
        -> 1, 5, 9, 10 -> 1, 5, 7, 10
        只有当后续小的数把最大数都覆盖了，那么这个序列才代表新的序列
        否则这个序列的大小仍然是等于被它覆盖掉的那个数的序列
    */
    
	if (array.size() == 0)
		return;
	
	// 错误的语法，这样 temp 的 size 直接就非零了，在push_back的时候是从
	// size 之后开始的 	
	//vector<int> temp(array.size() / 2);
	vector<int> temp; 
	temp.push_back(array[0]);
	for (int i=0; i<array.size(); i++) {
		if (array[i] > temp.back()) {
			temp.push_back(array[i]);
		} else {
			auto it = lower_bound(temp.begin(),temp.end(), array[i]);
			*it = array[i];
		}
	}
	
	cout << "solution 2: " << temp.size() << endl;
}

int main(int argc, char **argv)
{
	vector<int> array;
	
	array.push_back(7);
	array.push_back(1);
	array.push_back(5);
	array.push_back(4);
	array.push_back(3);
	array.push_back(2);
	array.push_back(9);
	array.push_back(6);
	array.push_back(8);
	array.push_back(10);
	array.push_back(17);
	array.push_back(11);
	array.push_back(55);
	array.push_back(54);
	array.push_back(13);
	array.push_back(24);
	array.push_back(29);
	array.push_back(56);
	array.push_back(18);
	array.push_back(11);
	
	solution_1(array);
	solution_2(array);
	
	return 0;
} 
