// Room: /open/capital/room/r60.c

#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "競技場前廣場");
	set( "build", 12 );
  set ("long", @LONG
北方是城內著名的競技場，由於王朝人人崇武，因而乾通天趁機在
此開設競技場供各方好手切磋武藝，一年一度的武狀元選拔也是在此舉
行的。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"fight",   
  "west" : __DIR__"r59",
  "east" : __DIR__"r62",
]));
  set("outdoors", "/open/capital");
set("objects",([
	CAPITAL_NPC"g1"	: 1,
	CAPITAL_NPC"g0"	: 1,
]));

  setup();
}
