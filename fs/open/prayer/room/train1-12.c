//open/prayer/room/train1-12

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇練武場");
  set ("long", @LONG

	    你眼前這位聖火教徒，正練著先天乾坤功
	，看他用招虎虎生風，看來也不是一個好惹的
	傢伙． 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" : 1,		//弟子
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 4 */
	"north" : "/open/prayer/room/train1-7",		//`練武場
	"south" : "/open/prayer/room/train1-17",		//`練武場
	"east" : "/open/prayer/room/train1-11",		//`練武場
	"west" : "/open/prayer/room/train1-13",		//`練武場
]));

  setup();
}
 
