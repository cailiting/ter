//����
class block {
public:
    void generate();                                //�������
    void  change();                                 //����
    void fall_speed();                              //���ٺ�����
    void left_right_move();                         //�����ƶ�
    void color();                                   //��ɫ
private:
    int shape[7][4][2] = 
    {               {{2,6},{2,7},{3,6},{3,7}},       //��1�ֻ������顰�
                    {{1,7},{2,7},{2,6},{3,6}},       //��2�ֻ������顰z��
                    {{1,6},{2,6},{2,7},{3,7}},       //��3�ֻ������鵹��z��
                    {{2,6},{3,6},{3,7},{3,8}},       //��4�ֻ������鷴��L��
                    {{2,8},{3,8},{3,7},{3,6}},       //��5�ֻ������顰L��
                    {{3,5},{3,6},{3,7},{3,8}},       //��6�ֻ������顰|��
                    {{2,7},{3,6},{3,7},{3,8}}};      //��7�ֻ������顰T��
};
//���
class play {
public:
    int addscore();                 //��������
    void pause();                   //��ͣ
    void test_key();                //��ⰴ����wasd������ �� �� ����
private:
    string name;
    int score;
};
//��Ⱦ
//win32
//1.��ƴ�����
    TCHAR szAppClassName[] = L" cc-elsfk";
    WNDCLASS wc = { 0 };
    wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WindowProc;
    wc.lpszClassName = szAppClassName;
    wc.style = CS_HREDRAW | CS_VREDRAW;
//2.ע�ᴰ����
    RegisterClass(&wc);
//3.��������
    HWND hWnd = CreateWindow();
//4.��ʾ����
    ShowWindow(hWnd, SW_SHOW);
//5.���´���
    UpdateWindow(hWnd);
//6.��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
//��Ϸ
class game {
public:
    void begin();               //��ʼ
    void end();                 //�жϽ���
    void add();                 //�ӷ�
    void add_line();            //����
    void decrease_line();       //����
    void show_score();          //��ʾ����
};