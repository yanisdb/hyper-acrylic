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

int main(int argc, const char* argv[])
{
	HWND hwnd = (HWND)atoi(argv[1]);
	boolean enable = argc < 2 || (argc >= 2 && argv[2] != "false");

	const HINSTANCE hModule = LoadLibrary(TEXT("user32.dll"));
	if (hModule) {
		typedef BOOL(WINAPI* pSetWindowCompositionAttribute)(HWND, WINCOMPATTRDATA*);
		const pSetWindowCompositionAttribute
			SetWindowCompositionAttribute = (pSetWindowCompositionAttribute)GetProcAddress(hModule, "SetWindowCompositionAttribute");
		if (SetWindowCompositionAttribute) {
			ACCENTPOLICY policy = { enable ? 3 : 0 , 0, 0, 0 };
			WINCOMPATTRDATA data = { 19, &policy, sizeof(ACCENTPOLICY) };
			SetWindowCompositionAttribute(hwnd, &data);
		}
		FreeLibrary(hModule);
	}
	return 0;
}