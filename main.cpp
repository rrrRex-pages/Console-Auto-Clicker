#include<iostream>
#include<windows.h>
#include<thread>
using namespace std;

#define KEY_DOWN GetAsyncKeyState
#define ME MOUSEEVENTF

char trig;
bool flag;
bool SwitchTrue;

void Switch()
{
	while (true)
	{
		if (KEY_DOWN(VK_RSHIFT))
		{
			while (KEY_DOWN(VK_RSHIFT))
			{
				flag = flag;
			}
			flag = !flag;
			cout << "flag=" << flag << endl;
		}
	}
}
void Right()
{
	while (!KEY_DOWN(VK_LSHIFT))
	{
		while (flag||KEY_DOWN(VK_RBUTTON))
		{
			while (KEY_DOWN(trig))
			{
				mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			}
		}
		
	}
}
void Left()
{
	while (!KEY_DOWN(VK_LSHIFT))
	{
		while (flag||KEY_DOWN(VK_LBUTTON))
		{
			while (KEY_DOWN(trig))
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
			}
		}
		
	}
}
int main()
{
	bool lr;
	cout << "Input 3 values:\n1.left/right(0 for right 1 for left\n2.trig:only alphabets!!!! please input those alphabets CAPITALIZED!!!!\n3.Switch: 0 for trig+mouse button, 1 for trig+mouse button or trig only. switch by rshift\nto exit, press lshift\n";
	cin >> lr >> trig >> SwitchTrue;
	if (SwitchTrue)
	{
		thread t(Switch);
		t.detach();
	}
	else
	{
		flag = true;
	}
	if (lr == true)
	{
		Left();
	}
	else
	{
		Right();
	}
}
