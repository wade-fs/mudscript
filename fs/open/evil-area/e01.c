#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",BBLU+YEL"震邪道" + NOR);
	set("long",@LONG
一個巨大的水濂呈現在你眼前, 水是由下往上流, 逆流而上, 真
可謂之人間絕景; 滔滔水聲, 氣勢澎湃, 你大略估計了一下水勢的強
度, 如果硬是要衝入水濂內的中, 很有可能會被強大的水壓給彈出通
道外。
LONG);
	set("exits",([
"north":__DIR__"e00",
"south":__DIR__"e02",
]));
	set("no_transmit",1);
	setup();
}

int valid_leave(object me,string dir)
{
	me=this_player();
	if(dir=="south")
	{
		if(!me->query_temp("evil/w_enter"))
		{
			message_vision(HIR + "
$N試著強行通過水濂，結果〔碰〕的一聲～

" + HIY + "$N被強大的水壓給彈出通道外！\n" + NOR,me);
		me->move(__DIR__"e00");
		return notify_fail("\n你重重的跌坐在地上，心底暗自喊痛...\n");
		}
	message_vision(HIC + "$N全身流動著一股淺藍色的氣流，緩緩著走向水濂內。\n" + NOR,me);
	return 1;
	}
return 1;
}
