#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "蜀中鐵鋪");
	set( "build", 3872 );
  set ("long", @LONG
 這裡是蜀中的打鐵鋪,幾個打鐵師父正在辛勤的工作,
牆上掛滿了做好的兵器,刀,劍等樣樣不缺,你可以在這
裡買些東西.	
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/gsword/room/su2.c",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/sells0" : 1,
]));


  setup();
}
