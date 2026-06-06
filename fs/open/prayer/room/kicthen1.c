//open/prayer/room/kicthen1

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG

	    你面前正有一個人忙的滿頭大汗，因為他
	要供應聖火教，門主以上的伙食，萬一有所差
	錯，難保有性命之憂．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/cooker" : 1,		//廚師
]));
  set("exits", ([ /* sizeof() ==  1*/
	"north" : "/open/prayer/room/kicthen3",		//`廚房
]));
   set("light_up", 1);
  setup();
}
 
