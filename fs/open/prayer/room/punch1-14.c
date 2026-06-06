//open/prayer/room/punch1-14

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇大聽");
  set ("long", @LONG

    在房間的角落，有一支五人環抱的盤龍大柱，這支大柱不但粗而且高
，看來聖火教的總壇的興建，一定是個浩浩蕩蕩的大工程，才會給人有種
氣勢磅礡的感覺． 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/major-officer" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/prayer/room/punch1-11",	//`大廳
	"east" : "/open/prayer/room/punch1-13",		//`大廳

]));
  set("light_up", 1);

  setup();
}
 
