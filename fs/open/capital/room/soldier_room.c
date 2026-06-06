// Room: /open/capital/room/r69.c
#include "../../open.h"
inherit ROOM;

void create ()
{
   set("short","軍機處");
  set ("long", @LONG
這裡是全國最高的軍事機構﹐在這裡﹐兵部尚書掌理全國兵馬﹐包
括軍隊的調配、差遣、訓練等等﹐充分的顯示其權力之大。
 
LONG);

  set("exits", ([ /* sizeof() == 1 */
	"east":"/open/capital/room/r72",
]));

  set("objects", ([ /* sizeof() == 1 */
	"/open/capital/npc/soldier_officer":1,
	]));

  set("no_fight", 1);

  set("light_up", 1);

  set("no_magic", 1);

  setup();
}
