//open/prayer/room/2elder2

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "執法長老房");
  set ("long", @LONG

    	    在你面前有一個小涼亭，在涼亭的四周，
	百花爭豔，鳥語花香，讓人有一種流連忘返的
	感覺．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee1" : 2,		//弟子
]));
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/2elder3",		//`長老房
	"east" : "/open/prayer/room/2elder5",		//`長老房
]));
 set("light_up", 1);

  setup();
}
 
