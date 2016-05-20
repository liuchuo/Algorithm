#include <iostream>
#include <vector>
using namespace std;
//函数声明
//欢迎界面和主菜单
void welcome();
void initaddbook();
void initaddvip();
void mainmenu();
void quit();

//关于图书管理部分的函数
void bookmanage();
void printbooklist();
void addbook();
void dropbook();
void loanbook();
void returnbook();

//关于会员管理部分的函数
void vipmanage();
void printviplist();
void addvip();
void dropvip();

void errorinfo();

//书本信息的结构体定义
struct book {
    int no;//书的编号
    string name;//书的名称可以相同但是编号必须唯一
    int amount;
};

//会员信息的结构体定义
struct vip {
    int no;//vip的编号
    string name;//vip的名字可以重复但是编号必须唯一
    vector<book> loanbook;
};

//结构体数组booklist和viplist
vector<book> booklist;
vector<vip> viplist;

//报错信息
void errorinfo() {
    cout << "~~~啊偶，灰常抱歉哦~~~" << endl;
    cout << "~~~系统检测到您输入指令有误~~~~~~~" << endl;
    cout << "~~~~~还烦请您重新输入呢~~~~~~~" << endl;
}

//退出系统
void quit() {
    cout << "~~~(｡･･｡)~~~" << endl;
    cout << "感谢使用本系统！" << endl;
    cout << "再见~~~~(^_^)"<< endl;
    cout << "===================" << endl;
}

//主菜单
void mainmenu() {
    cout << " —————————————(*^_^*)——————————————— " << endl;
    cout << "♥              .您好.                ♥" << endl;
    cout << "  ♥   .~这里就是传说中的主菜单了~.     ♥" << endl;
    cout << "♥    .请输入对应的指令编号进行操作.       ♥" << endl;
    cout << "  ♥                                ♥" << endl;
    cout << "♥           并按回车键结束              ♥" << endl;
    cout << "  ♥                                ♥" << endl;
    cout << "♥   1.图书管理 2.会员管理 3.退出系统      ♥" << endl;
    cout << "  ♥                                ♥" << endl;
    cout << " —————————————(*^_^*)——————————————— " << endl;
    cout << "键入我的指令：";
    int amenu;
    cin >> amenu;
    if(amenu == 1) {
        bookmanage();
    }else if(amenu == 2) {
        vipmanage();
    }else if(amenu == 3) {
        quit();
        
    } else {
        errorinfo();
        mainmenu();
    }
}

//图书管理界面
void bookmanage() {
    cout << "欢迎进入图书管理页面~请输入对应的指令编号进行操作~并按回车键结束~" << endl;
    cout << "1.查看所有图书信息  2.增加图书  3.删除图书  4.借阅图书 5.还书 6.返回主菜单 7.退出系统" << endl;
    cout << "键入我的指令：";
    int temp;
    cin >> temp;
    //查看所有的图书信息
    if(temp == 1) {
        printbooklist();
        cout << "所有图书信息显示完毕，正在返回图书管理界面....." << endl;
        cout << "返回成功！" << endl;
        bookmanage();
    //增加图书
    } else if(temp == 2) {
        addbook();
        cout << "增加图书成功- -！正在返回图书管理界面..." << endl;
        cout << "返回成功！" << endl;
        bookmanage();
    //删除图书
    } else if(temp == 3) {
        dropbook();
        cout << "删除图书成功- -！正在返回图书管理界面..." << endl;
        cout << "返回成功！" << endl;
        bookmanage();
    //借阅图书
    } else if(temp == 4) {
        loanbook();
        cout << "借阅图书成功- -！正在返回图书管理界面..." << endl;
        cout << "返回成功！" << endl;
        bookmanage();
    //还书
    }else if(temp == 5) {
        returnbook();
    //返回主菜单
    }if(temp == 6) {
        mainmenu();
    //退出系统
    }else if(temp == 7) {
        quit();
    //输入异常处理
    }else{
        errorinfo();
        bookmanage();
    }
}

//打印图书列表
void printbooklist() {
    cout << "===============================================================" << endl;
    for(vector<book>::iterator it = booklist.begin(); it != booklist.end(); it++) {
        cout << endl << "图书编号：" << (*it).no << endl;
        cout << "图书名称：" << (*it).name << endl;
        cout << "可借阅的数量：" << (*it).amount << endl;
    }
    cout << "===============================================================" << endl;
}

//增加图书
void addbook() {
    cout << "1.增加已有图书的数量 2.增加新的图书 3.返回主菜单" << endl;
    cout << "键入我的指令：";
    int temp;
    cin >> temp;
    //增加已有图书的数量
    if(temp == 1) {
        cout << "正在打印库存图书列表....." << endl;
        printbooklist();
        cout << "请输入想要增加的图书的编号：";
        int tno;
        cin >> tno;
        cout << "请输入想要增加的数量：";
        int tamount;
        cin >> tamount;
        while(tamount <= 0) {
            cout << "警告！输入的数量必须大于0！请重新输入:";
            cin >> tamount;
        }
        int flag = 0;
        for(vector<book>::iterator it = booklist.begin(); it != booklist.end(); it++) {
            if((*it).no == tno) {
                (*it).amount += tamount;
                flag = 1;
                return ;
            }
        }
        if(flag == 0) {
            cout << "未找到的图书编号...增加图书失败...请重新添加";
            addbook();
        }
        //添加新的图书信息
    }else if(temp == 2) {
        cout << "请输入想要增加的图书编号：";
        int tno;
        cin >> tno;
        int flag = 0;
        //判断是否想要增加的书的编号已经存在
        for(vector<book>::iterator it = booklist.begin(); it != booklist.end(); it++) {
            if((*it).no == tno) {
                flag = 1;
            }
        }
        if(flag == 1) {
            cout << "对不起，该编号的书已经存在，不能重复添加！" << endl;
            cout << "正在返回增加页面.." << endl;
            addbook();
        }
        cout << "请输入书名：";
        string tname;
        cin >> tname;
        cout << "请输入增加的数量：";
        int tamount;
        cin >> tamount;
        while(tamount <= 0) {
            cout << "警告！输入的数量必须大于0！请重新输入:";
            cin >> tamount;
        }
        book one;
        one.no = tno;
        one.name = tname;
        one.amount = tamount;
        booklist.push_back(one);
        //返回主菜单
    }else if(temp == 3) {
        mainmenu();
    }else {
        errorinfo();
        addbook();
    }
}

//删除图书
void dropbook() {
    cout << "正在打印图书列表..." << endl;
    printbooklist();
    cout << "请输入要删除图书的编号:";
    int tno;
    cin >> tno;
    for(vector<book>::iterator it = booklist.begin(); it != booklist.end(); it++) {
        if((*it).no == tno) {
            booklist.erase(it);
            return ;
        }
    }
    cout << "删除图书失败！未找到对应的编号..." << endl << "正在返回...";
    dropbook();
}

//租借图书
void loanbook() {
    cout << "请输入您的会员id：";
    int id;
    cin >> id;
    int flag = 0;
    //检测输入的会员号是否能找到，如果找不到要新注册一个才可以借书
    vector<vip>::iterator itt = viplist.begin();
    for(; itt != viplist.end(); itt++) {
        if((*itt).no == id) {
            flag = 1;
        }
    }
    if(flag == 0) {
        cout << "未找到该会员，请先注册...";
        addvip();
        return ;
    }
    cout << "正在打印图书列表..." << endl;
    printbooklist();
    cout << "请输入要借阅的图书编号：";
    int tbookno;
    cin >> tbookno;
    cout << "请输入要借阅的书籍数量：";
    int tamount;
    cin >> tamount;
    //检测想要借阅的书籍的数量是否充足
    for(vector<book>::iterator it = booklist.begin(); it != booklist.end(); it++) {
        if((*it).no == tbookno) {
            if((*it).amount < tamount) {
                cout << "对不起，书籍数量不足，借阅失败- -！...正在返回...";
                loanbook();
            } else {
                (*it).amount -= tamount;
                book record = (*it);
                //将vip信息内的借阅信息去除
                for(vector<vip>::iterator ittt = viplist.begin(); ittt != viplist.end(); ittt++) {
                    for(int i = 0; i < (*ittt).loanbook.size(); i++) {
                        if((*ittt).loanbook[i].no == tbookno) {
                            (*ittt).loanbook[i].amount -= tamount;
                            return ;
                        }
                    }
                }
                (*itt).loanbook.push_back(record);
                return ;
            }
        }
    }
}

//还图书
void returnbook() {
    cout << "请输入您的会员id：";
    int id;
    cin >> id;
    int flag = 0;
    //判断有没有该会员id的存在，不存在的话要先注册
    vector<vip>::iterator itt = viplist.begin();
    for(; itt != viplist.end(); itt++) {
        if((*itt).no == id) {
            flag = 1;
        }
    }
    if(flag == 0) {
        cout << "未找到该会员，请先注册...";
        addvip();
        return ;
    }
    
    cout << "正在打印vip列表..." << endl;
    printviplist();
    cout << "请输入要还的图书编号：";
    int tbookno;
    cin >> tbookno;
    cout << "请输入要还的书籍数量：";
    int tamount;
    cin >> tamount;
    int flag1 = 0;//判断会员信息内是否能找到这本要还的书，能找到的话flag1 = 1，否则为0
    //检测对应的vip信息内有无借了这么多书
    for(vector<vip>::iterator it = viplist.begin(); it != viplist.end(); it++) {
        if((*it).no == id){
            for(int i = 0; i < (*it).loanbook.size(); i++) {
                if((*it).loanbook[i].no == tbookno) {
                    if((*it).loanbook[i].amount < tamount) {
                        cout << "还书失败- -！...您并没有借了这么多书...";
                        returnbook();
                    }
                    (*it).loanbook[i].amount -= tamount;
                }
            }
            flag1 = 1;
        }
    }
    if(flag1 == 0) {
        cout << "未找到该本要还的书...正在返回...";
        returnbook();
    }
    
    int flag2 = 0;//判断booklist内是否能找到这本要还的书，能找到的话flag2 = 1，否则为0
    for(vector<book>::iterator itt = booklist.begin(); itt != booklist.end(); itt++) {
        if((*itt).no == tbookno) {
            (*itt).amount += tamount;
            flag2 = 1;
            return ;
        }
    }
    if(flag2 == 0) {
        cout << "未未找到该本要还的书...正在返回...";
        returnbook();
    }
}

//会员管理界面
void vipmanage() {
    cout << "欢迎进入会员vip管理页面~请输入对应的指令编号进行操作~并按回车键结束~" << endl;
    cout << "1.查看会员列表  2.增加会员信息  3.删除会员  4.返回主菜单" << endl;
    int temp;
    cin >> temp;
    if(temp == 1) {
        printviplist();
        cout << "列表显示成功- -！正在返回vip界面..." << endl;
        vipmanage();
    } else if(temp == 2) {
        addvip();
        cout << "增加会员成功- -！正在返回vip管理界面..." << endl;
        cout << "返回成功！" << endl;
        vipmanage();
    } else if(temp == 3) {
        dropvip();
        cout << "删除会员成功- -！正在返回vip管理界面..." << endl;
        cout << "返回成功！" << endl;
        vipmanage();
    } else if(temp == 4) {
        mainmenu();
    } else {
        errorinfo();
        vipmanage();
    }

}

//打印会员信息列表
void printviplist() {
    cout << "===============================================================" << endl;
    for(vector<vip>::iterator it = viplist.begin(); it != viplist.end(); it++) {
        cout << "会员id：" << (*it).no << endl;
        cout << "会员名：" << (*it).name << endl;
        cout << "该会员未归还的图书记录：" << endl;
        vector<book> v = (*it).loanbook;
        //如果会员信息内某本书的借阅为0，那么删除该条记录
        for(vector<book>::iterator itt = v.begin(); itt != v.end(); itt++) {
            if(itt->amount == 0) {
                v.erase(itt);
                continue;
            }
            cout << "书编号：" << itt->no << "  " << "书名：" << itt->name << "  " << "借阅的数量" << itt->amount << endl;
        }
        cout << endl;
    }
    cout << "===============================================================" << endl;
}


//增加会员
void addvip() {
    cout << "请输入想要增加的id:";
    int id;
    cin >> id;
    //检测会员id是否已经存在
    for(vector<vip>::iterator it = viplist.begin(); it != viplist.end(); it++) {
        if((*it).no == id) {
            cout << "抱歉，该id已经存在，请重新输入！...";
            addvip();
        }
    }
    cout << "请输入您的姓名：";
    string vipname;
    cin >> vipname;
    vector<book> vv;
    vip viprecord;
    viprecord.no = id;
    viprecord.name = vipname;
    viprecord.loanbook = vv;
    viplist.push_back(viprecord);
}

//删除会员
void dropvip() {
    cout << "正在打印vip列表...";
    printviplist();
    cout << "请输入想要删除的会员的id：";
    int id;
    cin >> id;
    int flag = 0;
    for(vector<vip>::iterator it = viplist.begin(); it != viplist.end(); it++) {
        if((*it).no == id) {
            viplist.erase(it);
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        cout << "找不到对应的会员id！请重新输入...";
        dropvip();
    }
}

//初始化增加书籍信息
void initaddbook() {
    book bookrecord;
    bookrecord.no = 0, bookrecord.name = "计算机程序设计艺术", bookrecord.amount = 20;
    booklist.push_back(bookrecord);
    bookrecord.no = 1, bookrecord.name = "深入理解计算机系统", bookrecord.amount = 17;
    booklist.push_back(bookrecord);
    bookrecord.no = 2, bookrecord.name = "算法导论", bookrecord.amount = 5;
    booklist.push_back(bookrecord);
    bookrecord.no = 3, bookrecord.name = "离散数学及其应用", bookrecord.amount = 2;
    booklist.push_back(bookrecord);
    bookrecord.no = 4, bookrecord.name = "设计模式精解", bookrecord.amount = 8;
    booklist.push_back(bookrecord);
    bookrecord.no = 5, bookrecord.name = "Microsoft .NET程序设计技术", bookrecord.amount = 6;
    booklist.push_back(bookrecord);
    bookrecord.no = 6, bookrecord.name = "计算机图形学(第三版)", bookrecord.amount = 7;
    booklist.push_back(bookrecord);
    bookrecord.no = 7, bookrecord.name = "数据结构与算法分析-Java语言描述", bookrecord.amount = 14;
    booklist.push_back(bookrecord);
    bookrecord.no = 8, bookrecord.name = "计算机科学概论：第8版", bookrecord.amount = 19;
    booklist.push_back(bookrecord);
    bookrecord.no = 9, bookrecord.name = "UNIX环境高级编程", bookrecord.amount = 5;
    booklist.push_back(bookrecord);
    bookrecord.no = 10, bookrecord.name = "C高效编程：内存与性能优化", bookrecord.amount = 9;
    booklist.push_back(bookrecord);
    bookrecord.no = 11, bookrecord.name = "神经网络设计", bookrecord.amount = 6;
    booklist.push_back(bookrecord);
}

//初始化增加会员信息
void initaddvip() {
    vip viprecord;
    book bookrecord;
    vector<book> v;
    //张三的信息
    bookrecord.no = 0, bookrecord.name = "计算机程序设计艺术", bookrecord.amount = 1;
    v.push_back(bookrecord);
    bookrecord.no = 7, bookrecord.name = "数据结构与算法分析 -Java语言描述", bookrecord.amount = 2;
    v.push_back(bookrecord);
    bookrecord.no = 11, bookrecord.name = "神经网络设计", bookrecord.amount = 1;
    v.push_back(bookrecord);
    viprecord.no = 1, viprecord.name = "张三", viprecord.loanbook = v;
    viplist.push_back(viprecord);
    
    //李四的信息
    bookrecord.no = 2, bookrecord.name = "算法导论", bookrecord.amount = 1;
    v.push_back(bookrecord);
    bookrecord.no = 10, bookrecord.name = "C高效编程：内存与性能优化", bookrecord.amount = 3;
    v.push_back(bookrecord);
    bookrecord.no = 11, bookrecord.name = "神经网络设计", bookrecord.amount = 1;
    v.push_back(bookrecord);
    viprecord.no = 1, viprecord.name = "李四", viprecord.loanbook = v;
    viplist.push_back(viprecord);
}


//欢迎界面
void welcome() {
    cout << " —————————————(*^_^*)——————————————— " << endl;
    cout << "♥              .您好.                ♥" << endl;
    cout << "  ♥   .欢迎您使用图书借阅系统.        ♥" << endl;
    cout << "♥    .请输入对应的指令编号进行操作.       ♥" << endl;
    cout << "  ♥                                ♥" << endl;
    cout << "♥           并按回车键结束              ♥" << endl;
    cout << "  ♥                                ♥" << endl;
    cout << "♥    1.进入主菜单.   2.退出本系统       ♥" << endl;
    cout << "  ♥                                ♥" << endl;
    cout << " —————————————(*^_^*)——————————————— " << endl;
    cout << "键入我的指令：";
    int a;
    cin >> a;
    if(a == 1) {
        mainmenu();
    } else if(a == 2) {
        quit();
    } else {
        errorinfo();
    }
}

//主函数
int main() {
    initaddbook();
    initaddvip();
    welcome();
    return 0;
}