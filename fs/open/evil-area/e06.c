inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",BBLU+YEL + "震邪道" + NOR);
	set("long",@LONG
沉長的通道, 由你所站立的位置, 螺旋狀的階梯, 直值得往下延
伸, 你集中精神的注視著最底端, 只能看到火紅的一點, [ 那裡
可能就是火牆所結成的〔幻結界〕了...] 你心理這麼盤算著。
LONG);
	set("exits",([
"down":__DIR__"e07",
]));
	setup();
}
