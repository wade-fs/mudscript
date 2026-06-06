// Room: /open/badman/room/lake4.c
// written by powell 96.4.26@FS

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "湖中密道");
  set ("long", @LONG
這裏是密祕通道的盡頭，看了看這兒，你不禁覺的大自然的力
量可真是神奇，由於長年陰濕，石壁上長滿了青苔，地上滑濕的很
走路時得時時提神，才不會跌倒。前面是個黑幽幽的大洞(hole)，
不知道洞裏到底有些什麼。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lake4",
]));

  setup();
}

void init()
{
	add_action("do_look","look");
}

int do_look(string arg)
{
	object who;
	who = this_player();
	if (arg == "hole" ) {
	message_vision("$N突然覺的腳下一滑，驚忽一聲，已跌進洞穴。\n",who);
	who -> move(__DIR__"valley1");
	tell_object(who,"你定神一看，這洞穴居然別有洞天。\n");
	return 1;
	}
	return 0;
}	
