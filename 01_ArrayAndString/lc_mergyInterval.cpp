/**@file  mergyinterval
* @copyright    GPL
* @brief       leetcode 合并区间
* @details  以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
* 请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
* 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
* 输出：[[1,6],[8,10],[15,18]]
* 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
* 输入：intervals = [[1,4],[4,5]]
* 输出：[[1,5]]
* 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
* 作者：力扣 (LeetCode)
* 链接：https://leetcode-cn.com/leetbook/read/array-and-string/c5tv3/
* 来源：力扣（LeetCode）
* 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
* @author      MCL
* @date        2018-8-17
* @version     V1.0
**********************************************************************************
* @attention
* SDK版本：v2050.0.0
* @par 修改日志:
* <table>
* <tr><th>Date        <th>Version  <th>Author    <th>Description
* <tr><td>2020/02/17  <td>1.0      <td>MCL		 <td>创建初始版本
* </table>
*
**********************************************************************************
*/

#include "stdio.h"
#include <Windows.h>.
#include <iostream>
#include <stdint.h>


const int intervalCol = 2;
int intervals[][intervalCol] = { 1, 3, 2, 6, 8, 10,15, 18 };
//int intervals[][intervalCol] = { 4,5, 1,4 };
unsigned int intervalNum = sizeof(intervals) / sizeof(int);
int ret[4][2] = {};

/**@function mergyinterval_2
* @brief .
* @param[in]  .
* @return  .
*/
void mergyinterval_2()
{
    int (*ppInterval)[2] = intervals;
    int nIntervalNum = sizeof(intervals) / sizeof(int) / 2;
    BOOL *bIntervalStatus = new BOOL[nIntervalNum]();
    
    int TmpVal[2] = { -1,-1 };
    int TmpNum = -1;

    for (int n = 0; n < nIntervalNum; n++)
    {
        //1.找未查最小首区间号
        for (int i = 0; i < nIntervalNum; i++)
        {
            if (bIntervalStatus[i] == 0 && (intervals[TmpNum][0] > intervals[i][0] || TmpNum == -1))
            {
                TmpNum = i;
            }
        }

        bIntervalStatus[TmpNum] = 1;
        TmpVal[0] = intervals[TmpNum][0];
        TmpVal[1] = intervals[TmpNum][1];

        //2.找最小首区间的尾区间
        for (int j = 0; j < nIntervalNum; j++)
        {
            if (bIntervalStatus[j] == 0 && TmpVal[1] >= intervals[j][0])
            {
                TmpVal[1] = intervals[j][1];
                bIntervalStatus[j] = 1;
                j = 0;
            }
        }
        TmpNum = -1;
        ret[n][0] = TmpVal[0];
        ret[n][1] = TmpVal[1];
    }
    for (int n = 0; n < nIntervalNum; n++)
    {
        printf("ret[%d,%d]\n", ret[n][0], ret[n][1]);
    }

    return;
}

/**@function mergyinterval_1
* @brief .
* @param[in]  .
* @return  .
*/
void mergyinterval_1()
{
    int(*ppInterval)[2] = intervals;
    int nIntervalNum = sizeof(intervals) / sizeof(int) / 2;
    BOOL* bIntervalStatus = new BOOL[nIntervalNum]();

    int TmpVal[2] = { -1,-1 };
    int TmpNum = -1;
    int io = 0;
    //根据区间头部从小到大排序
    for (int i = 0; i < nIntervalNum - 1; i++) {
        for (int j = 0; j < nIntervalNum - i - 1; j++) {
            if (intervals[j][0] > intervals[j + 1][0]) {
                TmpVal[0] = intervals[j][0];
                TmpVal[1] = intervals[j][1];
                intervals[j][0] = intervals[j + 1][0];
                intervals[j][1] = intervals[j + 1][1];
                intervals[j + 1][0] = TmpVal[0];
                intervals[j + 1][1] = TmpVal[1];
            }
        }
    }
    TmpVal[0] = intervals[0][0];
    TmpVal[1] = intervals[0][1];
    int j;
    //区间1的尾部与区间2的头部做比较，看区间1是否包含区间2
    for (j = 0; j < nIntervalNum - 1; ++j) {
        if (intervals[j][1] >= intervals[j + 1][0] ) {
            if (intervals[j][1] < intervals[j + 1][1])
            {
                TmpVal[0] = intervals[j][0];
                TmpVal[1] = intervals[j + 1][1];
            }
        }
        else {            
            ret[io][0] = TmpVal[0];
            ret[io][1] = TmpVal[1];
            ++io;
            TmpVal[0] = intervals[j + 1][0];
            TmpVal[1] = intervals[j + 1][1];
        }
    }
    //最后一个区间保存
    ret[io][0] = TmpVal[0];
    ret[io][1] = TmpVal[1];

    for (int i = 0; i < nIntervalNum; i++)
    {
        printf("ret[%d,%d]\n", ret[i][0], ret[i][1]);
    }
}



int main(void)
{
    mergyinterval_1();

    system("pause");
    return 0;

}
