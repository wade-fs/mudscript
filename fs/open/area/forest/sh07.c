inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","海神廟　門前");
	set("long","
由一片片粉白的貝殼所推積而成的貝殼門，與火山角礫岩和凝灰
岩所構成的淺灰色圍牆，結實的包維護著整個廟宇，門檻上掛了一個
匾額，上面寫著"+HIB+"[海神廟]"+NOR+"，深藍色的字體和周圍包裹著森林顯出了一
份不協調的美感。

		"+HIB+"<<海神廟>>"+NOR+"
");
	set("exits",([
"west":__DIR__"sh06",
]));
	set("outdoors",1);
	setup();
}

void init()
{
add_action("do_enter","enter");
}

int do_enter(object me)
{
me = this_player();

	message_vision(HIC"$N進入海神廟\n"NOR,me);
	me->move("/open/area/sea-temple/s01");
return 1;
}
