void color(const unsigned short color1)
{
	if (color1 >= 0 && color1 <= 15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	/*0=ºÚÉ«	8=»ÒÉ«		1=À¶É«		9=µ­À¶É«	2=ÂÌÉ«		10=µ­ÂÌÉ«        ¡¡¡¡
	3=ºþÀ¶É«	11=µ­Ç³ÂÌÉ«		4=ºìÉ«		12=µ­ºìÉ«		5=×ÏÉ«
	13=µ­×ÏÉ«		6=»ÆÉ«		14=µ­»ÆÉ«		7=°×É«		15=ÁÁ°×É«*/
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
