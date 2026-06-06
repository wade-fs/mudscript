inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",YEL + "古代遺跡=亂葬室" + NOR);
	set("long",@LONG
    一大堆的骨骸就在你的腳底下，這裡猶如骨骸堆置處一般，所有
的骨骸加起來，少說也有上千人的份量，只不過並非全部都是人類的
骨骸，還有動物與一些不知名生物的骨骸。
    四周都是由黃土石磚堆積而成的一個四方形密閉空間，並沒有任
何其他的通道。
LONG);
	set("exits",([
		"west":__DIR__"a01",
		"south":__DIR__"a04",
	]));
	set("no_transmit",1);
	setup();
}
