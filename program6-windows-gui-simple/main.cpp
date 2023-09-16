#include <windows.h>

// Global variables
HINSTANCE hInstance;
HWND hwnd;
const TCHAR* windowTitle = TEXT("Hello World");

// Background color
HBRUSH hBrushBackground = CreateSolidBrush(RGB(255, 140, 0)); // Dark Orange

// Custom cursor
HCURSOR hCursor = LoadCursor(NULL, IDC_ARROW); // You can replace IDC_ARROW with a custom cursor resource if desired

// Forward declarations of functions
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Store the application instance
    ::hInstance = hInstance;

    // Register the window class
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, windowTitle, NULL };
    ::RegisterClassEx(&wc);

    // Create the application window with the WS_THICKFRAME style for resizing
    hwnd = ::CreateWindow(wc.lpszClassName, windowTitle, WS_OVERLAPPEDWINDOW | WS_THICKFRAME, 100, 100, 400, 200, NULL, NULL, wc.hInstance, NULL);

    // Set the custom cursor
    ::SetCursor(hCursor);

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Main message loop
    MSG msg;
    while (::GetMessage(&msg, NULL, 0, 0)) {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }

    // Unregister the window class
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = ::BeginPaint(hWnd, &ps);

            // Set background color
            ::FillRect(hdc, &ps.rcPaint, hBrushBackground);

            // Set text color
            ::SetTextColor(hdc, RGB(255, 255, 255)); // White
            ::SetBkMode(hdc, TRANSPARENT); // Make text background transparent

            // Display "Hello, World!"
            ::TextOut(hdc, 10, 10, TEXT("Hello, World!"), 13);

            ::EndPaint(hWnd, &ps);
        }
            break;

        case WM_CLOSE:
            ::DestroyWindow(hWnd);
            break;
        case WM_DESTROY:
            ::PostQuitMessage(0);
            break;
        case WM_SIZE:
            // Repaint the window on resize
            ::InvalidateRect(hWnd, NULL, TRUE);
            break;
        case WM_SETCURSOR:
            // Set cursor to the default arrow when inside the client area
            if (LOWORD(lParam) == HTCLIENT) {
                ::SetCursor(LoadCursor(NULL, IDC_ARROW));
                return TRUE;
            }
            break;
        case WM_NCHITTEST:
        {
            LRESULT hitTest = ::DefWindowProc(hWnd, msg, wParam, lParam);

            if (hitTest == HTCLIENT) {
                return hitTest; // Keep the default arrow cursor for the client area
            } else {
                // Adjust the cursor for resize borders and corners
                switch (hitTest) {
                    case HTLEFT:
                    case HTRIGHT:
                        ::SetCursor(LoadCursor(NULL, IDC_SIZEWE));
                        break;
                    case HTTOP:
                    case HTBOTTOM:
                        ::SetCursor(LoadCursor(NULL, IDC_SIZENS));
                        break;
                    case HTTOPLEFT:
                    case HTBOTTOMRIGHT:
                        ::SetCursor(LoadCursor(NULL, IDC_SIZENWSE));
                        break;
                    case HTTOPRIGHT:
                    case HTBOTTOMLEFT:
                        ::SetCursor(LoadCursor(NULL, IDC_SIZENESW));
                        break;
                    default:
                        ::SetCursor(LoadCursor(NULL, IDC_ARROW));
                        break;
                }
                return hitTest;
            }
        }
        default:
            return ::DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}
