// uptime.c 加總時間 by ACKY

inherit F_CLEAN_UP;

int main()
{
	int tmp, total_time;

	seteuid(getuid());

	tmp = uptime();
	total_time = time() - 811699200; // 🚀 從 1995-09-22 開始計算

	printf( "[狂想空間]已經連續執行%s。\n總共執行%s。\n現在時間: %s\n",
		CHINESE_D->chinese_period(tmp),
    CHINESE_D->chinese_period(total_time),
		ctime(time()) );

/*
	if( wizardp(this_player()) )
		printf( "uptime = %d\n", uptime() );
*/

	return 1;
}

int help( object me )
{
	write(@HELP
指令格式: uptime

查詢[狂想空間]分別己經連續執行和總共執行了多久。
及 server 目前的時間。

HELP);
	return 1;
}
