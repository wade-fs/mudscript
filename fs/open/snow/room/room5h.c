#include <room.h>
#include <ansi.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
          object ob;
           ob=this_player();
          set("short","八卦陣陣眼");
        set("valid_startroom", 1);
set("long","這裡就是八卦陣的陣眼(eye)，從這裡就可以離開八卦陣。\n");
        set("exits", ([
	"north":__DIR__"room5",
	"south":__DIR__"room5b",
	"west":__DIR__"room5c",
	"east":__DIR__"room5b",
        ]) );
	set("objects",([SNOW_NPC"cmatetwo":1]));
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
	"$N從這裡找了找﹐突然觸碰了暗門﹐使陣眼打了開來。\n",this_player());
	set("exits",([
	"north":__DIR__"room5",
	"south":__DIR__"room5b",
	"east":__DIR__"room5b",
	"west":__DIR__"room5c",
	"out":__DIR__"8_out",
	]));
	return 1;
}
