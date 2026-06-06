inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",RED"陰曹入口"NOR);
	set("long",@LONG
    你已經來到了陰間的入口。雖然距離地府還有一段距離，但是你已經
感受到陣陣刺骨的陰風。四周一片荒涼，但是卻鬼影幢幢，看來這邊的夜
總會蠻熱鬧的，應該不愁沒伴。南邊和上面好像是和人世間相通的管道，
不過好像有一股無形的力量隔開這兩個不同的世界，看來要從這兩個方向
回去不是那麼簡單的事情。
LONG);
	set("objects",([
	__DIR__"npc/black":1,
	]));
	set("no_transmit",1);
	setup();
}
