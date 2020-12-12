#include <dwmapi.h>

struct ACCENTPOLICY {
	int nAccentState;
	int nFlags;
	int nColor;
	int nAnimationId;
};
struct WINCOMPATTRDATA {
	int nAttribute;
	PVOID pData;
	ULONG ulDataSize;
};

/// <summary>
/// 
/// </summary>
/// <param name="argv[1]"> The handle of the window</param>
/// <param name="argv[2]"> The type of blur, i.e., 0 for transparent blur and 1 for acrylic</param>
/// <param name="argv[3]"> The red value</param>
/// <param name="argv[4]"> The green value</param>
/// <param name="argv[5]"> The bluevalue</param>
/// <param name="argv[6]"> The alpha value</param>
/// <returns></returns>
int main(int argc, const char* argv[])
{
	HWND hwnd = (HWND)atoi(argv[1]);
	int state = atoi(argv[2]) + 2;
	int color = atoi(argv[3]) | (atoi(argv[4]) << 8) | (atoi(argv[5]) << 16) | (atoi(argv[6]) << 24);

	const HINSTANCE hModule = LoadLibrary(TEXT("user32.dll"));
	if (hModule) {
		typedef BOOL(WINAPI* pSetWindowCompositionAttribute)(HWND, WINCOMPATTRDATA*);
		const pSetWindowCompositionAttribute
			SetWindowCompositionAttribute = (pSetWindowCompositionAttribute)GetProcAddress(hModule, "SetWindowCompositionAttribute");
		if (SetWindowCompositionAttribute) {
			ACCENTPOLICY policy = { state, 0, color , 0 };
			WINCOMPATTRDATA data = { 19, &policy, sizeof(ACCENTPOLICY) };
			SetWindowCompositionAttribute(hwnd, &data);
		}
		FreeLibrary(hModule);
	}
	return 0;
}