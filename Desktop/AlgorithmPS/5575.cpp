#include <iostream>

using namespace std;

int main()
{
	for (int i = 1; i <= 3; i++)
	{
		int sh, sm, ss;
		int eh, em, es;
		cin >> sh >> sm >> ss;
		cin >> eh >> em >> es;

		int ws = (eh - sh) * 3600 + (em - sm) * 60 + (es - ss);
		int wh = ws / 3600;
		int wm = (ws - wh * 3600) / 60;
		int was = (ws - wh * 3600 - wm * 60);
		cout << wh << " " << wm << " " << was << endl;
	}
}