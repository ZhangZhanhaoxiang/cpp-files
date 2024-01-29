#include <iostream>
#include <deque>
#include <random>
#include <algorithm>

using namespace std;

deque<char> POKER{'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};

// “玩家”类
class player
{
public:
    player();
    player(int id);
    player(int chip, int bet); // 初始化
    player(player *p);         // 复制构造函数
    void displayCards(bool a); // 显示手持有的牌
    void hit(int n);           // 要牌
    void stand();              // 停牌
    void doubleBet();          // 双倍
    void split();              // 分牌
    void insure();             // 买保险
    void countMark();          // 计算分数
    void displayMoney();       // 显示总筹码和下注
    int id;
    deque<char> cards;  // 手持有的牌
    int chip = 1000;    // 总筹码
    int wager = 0;      // 下注
    int insurance = 0;  // 保险金
    int mark = 0;       // 分数
    bool isInsured = 0; // 是否买保险
    bool isHitable = 1; // 是否可以要牌
    bool isSplitable = 0;
};

int main()
{
    player dealer(10000, 0);

    // 洗牌
    random_device rd;
    default_random_engine gen(rd());
    shuffle(POKER.begin(), POKER.end(), gen);

    int n = 0;
    cout << "请输入有几位玩家：";
    cin >> n;
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        player P(i);
    }

    for (int i = 1; i <= n; i++)
    {
        int wager = 0;
        cout << "对于玩家" << i + 1 << "：" << endl;
        cout << "请输入下注金额：";
        cin >> wager;
        P[1].Wager(wager);
        players[i].displayMoney();
        cout << endl;
    }
}

player::player(int ID)
{
    id = ID;
}

void player::displayMoney()
{
    cout << "当前玩家共下注" << wager << "筹码" << endl;
    cout << "当前玩家剩余金额为" << chip << "元" << endl;
}