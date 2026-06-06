inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + NOR);
	set("long",@LONG
兩旁的沙丘高聳，你有一種快窒息的壓迫感～眼前有一座土堆堆
置而成的屋子，在屋頂的排氣孔還不斷的冒著黑煙，感覺上十分的詭
異。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"south":__DIR__"a-06",
"enter":__DIR__"a-31",
]));
	setup();
}

 
