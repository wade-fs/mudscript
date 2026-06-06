#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          object ob;
           ob=this_player();
          set("short","七星陣陣眼");
        set("outdoors", 1);
       set("long", @LONG
四處陰森森的，空氣中瀰漫著一股不尋常的氣息，就連你帶進來
的火把也顯得十分的暗淡。這樣的場面使你怯步，心中一股寒意不禁
油然升起，有種聲音一直在叫你回頭，不要繼續往前走了....這裡就
是八卦七星陣的陣眼，從這裡就可以離開八卦七星陣。
LONG);
        set("exits", ([
	"north":__DIR__"room5",
	"south":__DIR__"room5b",
	"west":__DIR__"room5c",
	"east":__DIR__"room5b",
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
	"north":__DIR__"room5",
	"south":__DIR__"room5b",
	"east":__DIR__"room5b",
	"west":__DIR__"room5c",
	"out":__DIR__"road1",
	]));
	return 1;
}


