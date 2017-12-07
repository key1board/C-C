void color(const unsigned short color1)
{
	if (color1 >= 0 && color1 <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	/*0=��ɫ	8=��ɫ		1=��ɫ		9=����ɫ	2=��ɫ		10=����ɫ        ����
	3=����ɫ	11=��ǳ��ɫ		4=��ɫ		12=����ɫ		5=��ɫ
	13=����ɫ		6=��ɫ		14=����ɫ		7=��ɫ		15=����ɫ*/
}

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

}
