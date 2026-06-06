// Room: /open/grassland/r01
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "黃土路");
  set ("long", @LONG
荒涼的路面，佈滿碎石依條蜿蜒而去的小路末端是一間大大個帳棚，
神秘詭異的環境，不經讓人提心吊膽，前方強大的氣息陣陣傳來，令你每
踏出一步都感到沉重的壓力，不短的路徑，走起來卻彷彿千年般的漫長。
門口站著二位士兵，只能從旁邊爬(climb)過去了。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"r02",
  "west" : __DIR__"grass21"
]));
  set("objects",([
  __DIR__"npc/patrol2.c":2
  ]));
  set("outdoors", "/open/grassland");
  set("no_transmit", 1);
  set("no_scale",1);
  set("no_kill",1);
  set("no_roar",1);
  set("no_fight",1);
  setup();
}
void init()
{
	add_action("do_climb","climb");
}
int do_climb(string arg)
{
	object me = this_player();
	me->move(__DIR__"r02.c");
	tell_object(me,HIG + "你小心奕奕的穿過警衛，看來要穿過警衛的話要先躲好(hide)。\n" + NOR);
	return 1;
}
int valid_leave(object me,string path)
{
	if(path == "east")
	{
	return notify_fail("這裡警備深嚴，你不敢隨便進去。\n");
	}
	return 1;
}
