#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Poker    // 定义“扑克”结构体
{
    int suit;   // 花色
    int points;   // 点数
};
Poker p[5];// 定义五张牌
int d;  // 两牌之间的“距离”

void swap(Poker &a, Poker &b)   // 重载swap交换函数
{
    swap(a.points, b.points);
    swap(a.suit, b.suit);
}

void random_poker() // 洗牌函数
{
    for (int i = 0; i < 5; i++)
        p[i].suit = rand() % 4 + 1;
    for (int i = 0; i < 5; i++)
        p[i].points = rand() % 13 + 1;
}

int abs(int a)// 绝对值函数
{
    return (a >= 0) ? a : (-a);
}

void bubble_sort(Poker arr[], int len)// 冒泡排序
{
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j].suit > arr[j + 1].suit)// 先按花色排列
            {
                swap(arr[j], arr[j + 1]);
            }
            else if (arr[j].suit == arr[j + 1].suit)// 若花色相同再按点数排列
            {
                if (arr[j].points > arr[j + 1].points)
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

}

void move_poker(int a)// 按“距离”排序
{
    bubble_sort(p + 1, 3);// 只给第1、2、3张牌排序
    switch (a)
    {
    case 1:
        break;
    case 2:
        swap(p[2], p[3]);
        break;
    case 3:
        swap(p[1], p[2]);
        break;
    case 4:
        swap(p[2], p[3]);
        swap(p[1], p[3]);
        break;
    case 5:
        swap(p[2], p[3]);
        swap(p[1], p[2]);
        break;
    case 6:
        swap(p[1], p[3]);
        break;
    }
    if (p[0].points + d > 13)// 按顺时针方向排列第一张和第四张
    {
        if (p[0].points + d - 13 != p[4].points)
            swap(p[0].points, p[4].points);
    }
    else if (p[0].points + d <= 13)
    {
        if (p[0].points + d != p[4].points)
            swap(p[0].points, p[4].points);
    }
}

void init() // 初始化
{
    cout << "正在洗牌……" << endl;
    cout << "正在抽出5张牌……" << endl;
    unsigned seed = time(0);
    srand(seed);
    random_poker();
    for (int i = 0; i < 5; i++) // 检查是否有重复的牌
    {
        for (int j = 0; j < 5; j++)
        {
            if (p[i].points == p[j].points && p[i].suit == p[j].suit && i != j)// 第i张和第j张不能是同一张牌
                random_poker();// 若有则重新洗牌
        }
    }
}

void game()
{
    for (int i = 0; i < 5; i++) // 遍历整幅牌，找出2张花色相同的牌放在第1张和第5张
    {
        for (int j = 0; j < 5; j++)
        {
            if (p[i].suit == p[j].suit && i != j)// 第i张和第j张不能是同一张牌
            {
                swap(p[i], p[0]);
                swap(p[j], p[4]);
                i = j = 5;  // 跳出两层循环
            }
        }
    }
    // 计算“距离”
    d = (abs(p[0].points - p[4].points) > 6) ? (13 - abs(p[0].points - p[4].points)) : (abs(p[0].points - p[4].points));
    move_poker(d);
}

int main()
{
    init();
    game();
    cout << "前四张牌分别为";
    for (int i = 0; i < 4; i++)
    {
        switch (p[i].suit)
        {
        case 1:
            cout << "\u2665";
            break;
        case 2:
            cout << "\u2666";
            break;
        case 3:
            cout << "\u2660";
            break;
        case 4:
            cout << "\u2663";
            break;
        }
        switch (p[i].points)
        {
        	case 11:
        	cout << "J";
        	break;
        	case 12:
        	cout << "Q";
        	break;
        	case 13:
        	cout << "K";
        	break;
        	default:
        	cout << p[i].points;
        	break;
        }
        cout << " ";
    }
    cout << "\n请推测第五张牌（\u2665=1，\u2666=2，\u2660=3，\u2663=4；A=1，J=11，Q=12，K=13）：" << endl;
    int m, n;
    cin >> m >> n;
    if (m == p[4].suit && n == p[4].points)
        cout << "猜对啦！" << endl;
    else
        cout << "猜错了." << endl;
    return 0;
}