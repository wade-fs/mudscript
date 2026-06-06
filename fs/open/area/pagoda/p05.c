inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",YEL"乾坤八卦塔"NOR);
	set("long",@LONG
每面牆壁筆直而上，略有往內收縮，共有八面牆壁，形成一個正
八角，十分的空曠，除了一座往上的木梯以外，整個空間看起來空蕩
蕩的。
LONG);
	set("exits",([
"up":__DIR__"p06",
"down":__DIR__"p04",
]));
	set("objects",([
__DIR__"npc/guard01":1,
]));
	set("mark",5);
	setup();
}
