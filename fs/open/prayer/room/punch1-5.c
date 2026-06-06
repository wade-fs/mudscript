//open/prayer/room/punch1-5

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "副教主的房間");
  set ("long", @LONG

    你來到了聖火教副教主與副教主夫人的房間，在房門之後有一位婀娜
多姿的婦人，清秀的瓜子臉上有著一絲哀怨的神情，難到副教主夫人有何
難言之隱.... 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/wife2" : 1,        	//軍師
]));  
set("exits", ([ /* sizeof() == 1 */
	"out" : "/open/prayer/room/punch1-3",		//`軍師
]));
  set("light_up", 1);

  setup();
}
 
