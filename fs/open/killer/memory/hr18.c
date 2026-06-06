#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "懸崖");
  set ("long", @LONG

	當你逐漸接近莫塔湖的源河之時，你心中不禁感嘆造物者的神奇。
	想不到在這種高山上竟然會有這麼壯闊的一條河流！！
	想到這裡，你不由的想更加的去接近這一條河流。。。。
LONG);

  set("exits", ([ /* sizeof() == 3   */
     "east" : __DIR__"hr19.c",   
     "west" : __DIR__"hr17.c",   
]));

  setup();
}
