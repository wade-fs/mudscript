#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "平南鐵鋪");
	set( "build", 1388 );
  set ("long", @LONG
這裡是平南城的打鐵鋪,幾個打鐵師父正在辛勤的工作,
牆上掛滿了做好的兵器,刀,劍等樣樣不缺,你可以在這裡買
東西.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road5",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/sells0" : 1,
]));
  set("light_up", 1);

  setup();
}
