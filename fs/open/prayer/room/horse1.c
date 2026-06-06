//open/prayer/room/horse1

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "馬房");
  set ("long", @LONG

　　　　    這是教主坐騎專用的馬房，派有專人的看
	管，因此這間馬房比其它馬房乾淨多了，而且
	面前的神駒，正是日行千里的爪黃飛電．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/horse-looker" : 1,		//馬夫
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() ==  1*/
	"west" : "/open/prayer/room/horse3",		//`馬房
]));

  setup();
}
 
