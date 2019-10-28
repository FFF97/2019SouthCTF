#include <windows.h>
#include <stdio.h>
#include <string.h>

#define IDC_SS_FLAG 1000
#define IDC_ES_EDIT 1001
#define IDC_BS_CHECK 1002

int str[] = {7, 13, 0, 6, 26, 4, 85, 84, 24, 62, 2, 19, 85, 2, 10, 62, 12, 4, 28};

struct {
    TCHAR * szStruct;
    TCHAR * szCaption;
    int iStyle;
    int IDC;
}
controls [] = {
    TEXT("STATIC"), TEXT("FLAG:"), BS_LEFT, IDC_SS_FLAG,
    TEXT("EDIT"), TEXT(""), WS_BORDER | ES_LEFT | ES_AUTOHSCROLL, IDC_ES_EDIT,
    TEXT("BUTTON"), TEXT("CHECK"), BS_DEFPUSHBUTTON, IDC_BS_CHECK
};

#define NUM (sizeof controls / sizeof controls[0])

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int CreateControls(HWND, HWND *, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    static TCHAR szAppName[] = TEXT("CrackMe");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.hInstance = hInstance;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = szAppName;
    wndclass.lpszMenuName = NULL;

    if(!RegisterClass(&wndclass))
        MessageBox(NULL, TEXT("无法注册窗口类！"), TEXT("错误"), MB_OK | MB_ICONERROR);
    hwnd = CreateWindow(
        szAppName, TEXT("CrackMe"),
        WS_TABSTOP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT,
        300, 100,
        NULL, NULL, hInstance, NULL 
    );
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);
    while(GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    static HWND hControls [ NUM ];
    static RECT rect;
    static int cxChar, cyChar;
    PAINTSTRUCT ps;
    HDC hdc;
    int i;
    switch(message) {
    case WM_CREATE:
        CreateControls(hwnd, hControls, lParam);    
        cxChar = LOWORD(GetDialogBaseUnits()); //获得窗口中内定字体字元宽度（低字组）
        cyChar = HIWORD(GetDialogBaseUnits()); //获得窗口中内定字体字元高度（高字组）
    return 0;
    case WM_SIZE:
        GetClientRect(hwnd, &rect);
        MoveWindow(hControls[ controls[0].IDC ], 10, 10, 50, cyChar * 7 / 5, TRUE);
        MoveWindow(hControls[ controls[1].IDC ], 60, 8, 220, cyChar * 7 / 5, TRUE);
        MoveWindow(hControls[ controls[2].IDC ], 100, 40, 100, cyChar * 7 / 5, TRUE);
    return 0;
    case WM_COMMAND:
        if((HWND)lParam == hControls[ controls[2].IDC ]) {
            char input[200];
            GetDlgItemText(hwnd, IDC_ES_EDIT, input, sizeof(input));
            int correct = 1;
            for(int i = 0; i < strlen(input); i++) {
                if(('a' ^ str[i]) != input[i]) {
                    correct = 0;
                    break;
                }
            }
            if(correct == 1)
                MessageBox(NULL, TEXT("CORRECT FLAG"), TEXT("TIPS"), MB_YESNO | MB_ICONQUESTION);
            else
                MessageBox(NULL, TEXT("WRONG FLAG"), TEXT("TIPS"), MB_YESNO | MB_ICONQUESTION);
        }
    return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}

int CreateControls(HWND hwnd, HWND * hControls, LPARAM lParam) {
    int i;
    HINSTANCE hInst = ((LPCREATESTRUCT) lParam) -> hInstance;
    for(i=0; i<NUM; i++)
        hControls [ controls[i].IDC ] = CreateWindow(
            controls[i].szStruct, 
            controls[i].szCaption,
            controls[i].iStyle | WS_CHILD | WS_VISIBLE,
            0, 0, 0, 0,
            hwnd,(HMENU) controls[i].IDC, hInst, NULL
        );
    return 0;
}