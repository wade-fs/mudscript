#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
          object ob;
           ob=this_player();
          set("short","八卦陣陣眼");
          set("long",@LONG
這裡就是五行八卦陣的八卦陣了，在此處你看到了滿地的武器，
四周漆黑如夜，伸手不見五指，遠遠望去，一道光線迎面而來，令你
想立刻飛奔過去，只見一陣陣的陰風撲面而來，此時才發覺有許多鬼
影向你這奔來。這裡就是八卦陣的陣眼，從這裡就可以離開八卦陣了
。
LONG);
        set("exits", ([
	"north":__DIR__"room6",
	"south":__DIR__"room6b",
	"west":__DIR__"room6c",
	"east":__DIR__"room6b",
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
	"north":__DIR__"room6",
	"south":__DIR__"room6b",
	"east":__DIR__"room6b",
	"west":__DIR__"room6c",
	"out":__DIR__"tower7-1",
	]));
	return 1;
}


