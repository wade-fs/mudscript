// Room: /open/tendo/room/t06.c

inherit ROOM;

void create()
{
	set("short", "道觀的外圍步道");
	set("long", @LONG
你正走在道觀的外圍步道上，上面鋪著堅硬的水磨青
磚，四周種滿了翠綠的數木，令人心神舒暢。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"t01",
  "east" : __DIR__"t07",
	"west" : __DIR__"t12",
]));
	set("light_up",1);
	setup();
}
/*
void init()
{
        add_action("do_search", "search");
}
*/

int do_search()
{
        object who;
        who = this_player();

        tell_object(who,"\n你趴在地上把書堆翻開，猛然看見一個地道，地道中的強"+
			   "烈氣流把你吸入了地道.....\n");
        who->move("/open/tendo/room/r0");
        tell_room(this_object(),"你看到"+who->query("name")+"被地道中的強烈氣"+
				 "流給吸入了.....\n");
        return 1;
}
