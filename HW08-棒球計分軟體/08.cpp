#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define SIZE 9

int main(void)
{
    int a[SIZE];
    string input[SIZE][20];
    char temp[3];
    int b;

    //讀取打擊結果
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &a[i]);
        for (int j = 0; j < a[i]; j++)
        {
            scanf("%s", temp);
            input[i][j] = temp;
        }
    }
    scanf("%d", &b);

    //計算分數
    int num = 0;       //打擊結果轉換後的值
    int point = 0;     //分數
    int out = 0;       //當局出局數
    int out_sum = 0;   //累積出局數
    int base[4] = {0}; //跑壘狀態，0壘上無人、1壘上有人，陣列索引分別對應，0:本壘, 1:一壘, 2:二壘, 3:三壘

    auto getNum = [&](string &point) {
        if (point == "1B")
            return 1;
        else if (point == "2B")
            return 2;
        else if (point == "3B")
            return 3;
        else if (point == "HR")
            return 4;
        return 0;
    };

    bool isOver = false;
    int index = 0;
    while (true)
    {
        for (int i = 0; i < SIZE; i++)
        {
            //超過最後一筆資料
            if (index > a[i])
            {
                isOver = true;
                break;
            }

            //將打擊結果轉換為數字
            num = getNum(input[i][index]);

            //出局
            if (num == 0)
            {
                out_sum++;
                out++;
            }
            //安打
            else
            {
                base[0] = 1; //將打擊者放在本壘
                for (int x = 3; x >= 0; x--)
                {
                    //如果壘上有人
                    if (base[x] == 1)
                    {
                        //回到本壘
                        if (x + num >= 4)
                        {
                            point++;
                        }
                        //未回到本壘
                        else
                        {
                            base[x + num] = 1;
                        }
                        base[x] = 0;
                    }
                }
            }
            //出局數達到結束條件
            if (out_sum == b)
            {
                isOver = true;
                break;
            }

            //達到三個出局數，清空跑壘狀態
            if (out == 3)
            {
                out = 0;
                base[0] = base[1] = base[2] = base[3] = 0;
            }
        }
        if (isOver)
        {
            break;
        }
        index++;
    }

    //印出結果
    printf("%d", point);
    return 0;
}