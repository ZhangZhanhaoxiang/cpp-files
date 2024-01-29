#include <iostream>
#include <random>
#include <deque>
#include <algorithm>

using namespace std;

deque<char> POKER{'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K', 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};

// “玩家”类
class player
{
public:
    player();
    player(int chip, int bet); // 初始化
    player(player *p);         // 复制构造函数
    void display(bool a);      // 显示手持有的牌
    void hit(int n);           // 要牌
    void stand();              // 停牌
    void doubleBet();          // 双倍
    void split();              // 分牌
    void insure();             // 买保险
    void countMark();          // 计算分数
    int printMark();           // 显示分数
    bool printIsHitable();
    void Wager(int bet); // 下注
    void displayMoney(); // 显示总筹码和下注

private:
    deque<char> cards;  // 手持有的牌
    int chip;           // 总筹码
    int wager = 0;      // 下注
    int insurance = 0;  // 保险金
    int mark = 0;       // 分数
    bool isInsured = 0; // 是否买保险
    bool isHitable = 1; // 是否可以要牌
};

player::player()
{
    this->chip = 1000;
    this->wager = 0;
}

player::player(int chip, int bet)
{
    this->chip = chip - bet;
    this->wager = bet;
}

// 复制构造函数
player::player(player *p)
{
    this->chip = 0;
    this->cards.push_back(p->cards.back());
    p->cards.pop_back();
    p->chip -= p->wager;
    p->wager *= 2;
    this->countMark();
    p->countMark();
}

// 计算分数
void player::countMark()
{
    this->mark = 0;
    for (int i = 0; i < this->cards.size(); i++)
    {
        if (this->cards.at(i) >= '2' && this->cards.at(i) <= '9')
        {
            this->mark += (int)(this->cards.at(i) - 48);
        }
        else if (this->cards.at(i) == '0' || this->cards.at(i) == 'J' || this->cards.at(i) == 'Q' || this->cards.at(i) == 'K')
        {
            this->mark += 10;
        }
        else if (this->cards.at(i) == 'A')
        {
            this->mark += 11;
        }
    }
    for (int i = 0; this->mark > 21 && i < this->cards.size(); i++)
    {
        if (this->cards.at(i) == 'A')
        {
            this->mark -= 10;
        }
    }
}

// 显示分数
int player::printMark()
{
    return this->mark;
}

bool player::printIsHitable()
{
    return this->isHitable;
}

// 要牌
void player::hit(int n)
{
    for (int i = 1; i <= n; i++)
    {
        this->cards.push_back(POKER.front());
        POKER.pop_front();
    }
    this->countMark();
}

// 显示手持的牌
void player::display(bool a)
{
    if (a == 0) // 如果a是0，则显示所有的牌
    {
        for (auto i = cards.begin(); i != cards.end(); ++i)
        {
            if (*i == '0')
                cout << "10 ";
            else
                cout << *i << " ";
        }
        // cout<<this->mark<<endl;
    }
    else // 如果a是1，则只显示第2张牌
    {
        if (this->cards.at(1) == '0')
            cout << "庄家的牌是：X 10 ";
        else
            cout << "庄家的牌是：X " << this->cards.at(1) << endl;
            cout << endl;
    }
}

// 双倍
void player::doubleBet()
{
    this->hit(1);
    this->chip -= this->wager;
    this->wager *= 2;
    this->isHitable = 0;
}

// 买保险
void player::insure()
{
    this->isInsured = 1;
    this->chip -= (int)this->wager * 0.5;
    this->wager *= 0.5;
}

// 停牌
void player::stand()
{
    this->isHitable = 0;
}

// 下注
void player::Wager(int bet)
{
    this->chip -= bet;
    this->wager += bet;
}

void player::displayMoney()
{
    cout << "当前玩家共下注" << this->wager << "筹码" << endl;
    cout << "当前玩家剩余金额为" << this->chip << "元" << endl;
}

// 操作
void operation(player *players)
{
    int opt = 0;
    while (players->printMark() <= 21 && players->printIsHitable() == 1)
    {
        cout << "牌面：";
        players->display(0);
        cout << endl;
        players->displayMoney();
        cout << endl;
        cout << "请进行操作：\n1.要牌\n2.停牌\n3.双倍\n4.分牌\n5.买保险\n6.显示牌面\n7.显示下注" << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            players->hit(1);
            continue;
        case 2:
            players->stand();
            continue;
        case 3:
            players->doubleBet();
            continue;
        case 4:
            players->split();
            continue;
        case 5:
            players->insure();
            continue;
        }
    }
    if (players->printMark() > 21)
    {
        cout << "爆牌了" << endl;
    }
}

// 分牌
void player::split()
{
    if (this->cards.at(0) != this->cards.at(1) && this->cards.size() != 2)
    {
        cout << "你的牌不能分牌。" << endl;
    }
    else
    {
        player temp = *this;
        player* p = &temp;
        operation(this);
        operation(p);
    }
}

int main()
{
    player dealer(10000, 0);

    // 洗牌
    random_device rd;
    default_random_engine gen(rd());
    // uniform_int_distribution<int> distribution(1,6);
    // int a=distribution(gen);
    shuffle(POKER.begin(), POKER.end(), gen);

    int a = 0;
    cout << "请输入有几位玩家：";
    cin >> a;
    cout << endl;
    player players[a];

    // 首次下注
    for (int i = 0; i < a; i++)
    {
        int wager = 0;
        cout << "对于玩家" << i + 1 << "：" << endl;
        cout << "请输入下注金额：";
        cin >> wager;
        players[i].Wager(wager);
        players[i].displayMoney();
        cout << endl;
    }

    // 第一轮发牌
    for (int i = 0; i < a; i++)
    {
        players[i].hit(2);
        cout << "第" << i + 1 << "位玩家的牌是：";
        players[i].display(0);
        cout << endl;
    }
    dealer.hit(2);
    dealer.display(1);

    for (int i=0;i<a;i++)
    {
        cout << "对于玩家" << i+1 << "：" << endl;

        operation(players+i);
    }

    return 0;
}