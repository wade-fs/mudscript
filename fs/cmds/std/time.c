// time.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	write("現在是" + NATURE_D->game_time() + "。\n");
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式 : time
指令說明 :
           這個指令讓你(妳)知道現在的狂想空間時辰。
其他參考 :
           date，uptime
HELP
    );
    return 1;
}
