#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          object ob;
           ob=this_player();
          set("short","四象陣陣眼");
          set("long",@LONG
你已經走入五行八卦陣的四象陣中，只見四周都是岩石，以及一
些困死在此的人的骸骨，在此你已無法辨明方向。腐爛的惡臭更是令
你無法忍受。再加上地面上都是爛泥，更是難走，腳上七高八低，望
出來黑漆一團，令人覺得一陰森恐怖。這裡就是四象陣的陣眼，從這
裡就可以離開四象陣了。
LONG);
        set("exits", ([
	"north":__DIR__"room2",
	"south":__DIR__"room2b",
	"west":__DIR__"room2c",
	"east":__DIR__"room2b",
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
	"north":__DIR__"room2",
	"south":__DIR__"room2b",
	"east":__DIR__"room2b",
	"west":__DIR__"room2c",
	"out":__DIR__"tower2-1",
	]));
	return 1;
}


