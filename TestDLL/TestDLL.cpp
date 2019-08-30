#include <string>
#include <Windows.h>

#include <comdef.h>
#include "..\Voukoder\IVoukoder.h"

//typedef int(*imp_init)();
//typedef int(*imp_open_config_dialog)(char* settings, HWND hwnd);
//typedef bool(*imp_encoder_open)(const char* settings);
//typedef void(*imp_encoder_close)();
//
//#define DYN(name) ((imp_##name)GetProcAddress(instance, #name))

int main()
{
	//HMODULE instance = LoadLibraryA("C:\\Users\\Daniel\\source\\repos\\voukoder\\Voukoder\\x64\\Debug\\voukoder.dll");
	//if (!instance)
	//{
	//	exit(1);
	//}

	//// Init voukoder
	//DYN(init)();

	//char settings[1024] = "{ \"filename\" : \"c:\\\\Users\\\\Daniel\\\\Desktop\\\\file.mp4\", \"audio\" : {\"enabled\" : true } }";


	//if (DYN(open_config_dialog)(settings, GetDesktopWindow()))
	//{
	//	OutputDebugStringA(settings);

	//	if (DYN(encoder_open)(settings))
	//	{
	//		DYN(encoder_close);
	//	}
	//}

	//FreeLibrary(instance);

	CoInitialize(NULL);
	HRESULT hr;
	
	IVoukoder *voukoder = (0);
	hr = CoCreateInstance(CLSID_Voukoder, NULL, CLSCTX_INPROC_SERVER, __uuidof(IVoukoder), (void**)&voukoder);
	if (FAILED(hr))
	{
		printf("failed to initialize COM server");
		return 1;
	}

	return 0;
}