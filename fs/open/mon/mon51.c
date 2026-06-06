inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "洞穴外");
	set( "build", 42 );
  set ("long", @LONG
慢慢的走近這裏一看，原來是一個山洞在這裏，深黑的山洞似乎
看不見底，山洞中還傳出來陣陣的吼聲，不知是什麼怪獸在裏頭，讓
你止步不敢向前。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/bembem.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"mon28",
  "enter" : __DIR__"mon52",
]));

  setup();
}
