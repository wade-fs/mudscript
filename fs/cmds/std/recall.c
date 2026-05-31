// recall.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int no_transmit,evil;
	object ob,where;
	string filep;
	seteuid(getuid());
	ob=this_player();

//    filep=ob->query("startroom")+".c";
	filep = "/open/common/room/inn.c";

    where = environment(ob);
    no_transmit = where->query("no_transmit",1);
    evil = where->query("evil",1);

	if( CLAN_D->what_clan_area(me) != "NULL" )
		return notify_fail( "無法在幫派區域內使用。\n" );

    if(no_transmit)
    {
     write("似乎天神聽不到你的呼喚聲...\n");
     return 1;
    }
    if(evil)
    {
     write("似乎天神的力量無法將你從魔界救出....\n");
     return 1;
    }
      if(me->query_temp("不准走")) return notify_fail("你現在不能移動!!\n");
        if( me->is_fighting() ) return notify_fail("你正在戰鬥中﹗\n");

     if(ob->query("max_kee") < 1000 && ob->query("kee") < 50)
       return notify_fail("你的氣不夠了, 無力來使用 recall..\n");
     if(ob->query("max_kee") > 1000)
       ob->add("kee",-50);

	if(file_size(filep)==-1){
	  return notify_fail("程式有問題喔！請通知大神處理～\n");
	          }

	message_vision(HIC"$P請求著天神將$P傳送回起點﹗\n"
HIW"突然由空中降下一道耀眼的光﹐罩住$P後消失不見了...\n"NOR,ob);

	            ob->move(filep);
              me->move(filep,1);
message_vision(HIW"突然由天上降下一道耀眼的光﹗\n"
	            HIY"$N由光芒內緩緩的走出來....\n"NOR,ob);
	              return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : recall


這個指令可以讓你(妳)迅速回到開始點，將會耗費你的精五十點。

HELP
    );
    return 1;
}
