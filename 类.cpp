//方块
class block {
public:
    void generate();                                //随机产生
    void  change();                                 //变形
    void fall_speed();                              //加速和下落
    void left_right_move();                         //左右移动
    void color();                                   //填色
private:
    int shape[7][4][2] = 
    {               {{2,6},{2,7},{3,6},{3,7}},       //第1种基本方块“田”
                    {{1,7},{2,7},{2,6},{3,6}},       //第2种基本方块“z”
                    {{1,6},{2,6},{2,7},{3,7}},       //第3种基本方块倒“z”
                    {{2,6},{3,6},{3,7},{3,8}},       //第4种基本方块反“L”
                    {{2,8},{3,8},{3,7},{3,6}},       //第5种基本方块“L”
                    {{3,5},{3,6},{3,7},{3,8}},       //第6种基本方块“|”
                    {{2,7},{3,6},{3,7},{3,8}}};      //第7种基本方块“T”
};
//玩家
class play {
public:
    int addscore();                 //分数计算
    void pause();                   //暂停
    void test_key();                //检测按键“wasd”“↑ ↓ ← →”
private:
    string name;
    int score;
};
//渲染
//win32
//1.设计窗口类
    TCHAR szAppClassName[] = L" cc-elsfk";
    WNDCLASS wc = { 0 };
    wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = szAppClassName;
    wc.style = CS_HREDRAW | CS_VREDRAW;
//2.注册窗口类
    RegisterClass(&wc);
//3.创建窗口
    HWND hWnd = CreateWindow();
//4.显示窗口
    ShowWindow(hWnd, SW_SHOW);
//5.更新窗口
    UpdateWindow(hWnd);
//6.消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
//游戏
class game {
public:
    void begin();               //开始
    void end();                 //判断结束
    void add();                 //加分
    void add_line();            //增行
    void decrease_line();       //消行
    void show_score();          //显示分数
};