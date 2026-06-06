#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          object ob;
           ob=this_player();
          set("short","五行陣陣眼");
          set("long",@LONG

你已邁入了五行八卦陣中的五行陣，在此處你看到了滿地的枯骨，
四周毫無光線，伸手不見五指，遠遠的望去，只看到一點亮光，令你想
立刻飛奔過去，只見一陣陣的陰風撲面而來，此時才發覺有許多的妖魅
向你這飛奔過來。這裡就是五行陣的陣眼，從這裡就可以離開五行陣了
。
LONG);
        set("exits", ([
	"north":__DIR__"room3",
	"south":__DIR__"room3b",
	"west":__DIR__"room3c",
	"east":__DIR__"room3b",
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
	"north":__DIR__"room3",
	"south":__DIR__"room3b",
	"east":__DIR__"room3b",
	"west":__DIR__"room3c",
	"out":__DIR__"tower4-1",
	]));
	return 1;
}


