#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
          object ob;
           ob=this_player();
          set("short","六儀陣陣眼");
          set("long",@LONG
這裡就是五行八卦陣中的六儀陣了，在此處你看到了一團團鬼火
，四周陰森森的，伸手不見五指，遠遠的望去，只看到幾處出口，令
你想立刻飛奔過去，只見一陣陣的陰風撲面而來，此時才發覺有許多
妖魔向你這奔來。這裡就是六儀陣的陣眼，從這裡就可以離開六儀陣
了。
LONG);
        set("exits", ([
	"north":__DIR__"room4",
	"south":__DIR__"room4d",
	"west":__DIR__"room4c",
	"east":__DIR__"room4d",
        ]) );
	set("objects",([
]));
        set("no_transmit",1);
          setup();
}
void init()
{
	add_action("do_search","search");
}
int do_search(string str)
{
	if(str!="eye") return 0;
	message_vision(
	"$N從這裡找了找﹐突然觸碰了岩石﹐使陣眼打了開來。\n",this_player());
	set("exits",([
	"north":__DIR__"room4",
	"south":__DIR__"room4b",
	"east":__DIR__"room4b",
	"west":__DIR__"room4c",
	"out":__DIR__"tower5-1",
	]));
	return 1;
}


