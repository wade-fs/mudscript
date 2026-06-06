inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC + "琰 揚 湖" + NOR);
	set("long",@LONG
你的腳下正踩著咒術陣，這裡是琰揚湖與外界的出路口，你可以
清楚的看到琰揚湖是一座被許多巨大的沙丘所包圍的湖泊，你四處的
打聽，得知琰揚湖是歸屬於邪靈主的部下--〔水邪將〕水柔纏　所管
理的，而水柔纏是所有的邪將內，與人類最為親近的邪將，她曾經將
一些人間界的人接到琰揚湖內居住，也許你該多問問其他還生存於此
地的人類有關於邪靈界與水柔纏的事情吧。
LONG);
	set("objects",([
__DIR__"npc/w_seller":1,
__DIR__"npc/mob03":2,
]));
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"east":__DIR__"a-01",
]));
	set("item_desc",([
"咒術陣":"這個咒術陣似乎只有接收的功\能，無法將人傳送去其他的地方。\n",
]));
	setup();
}
