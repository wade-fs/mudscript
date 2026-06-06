//open/prayer/room/punch1-11

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇大聽");
  set ("long", @LONG

    這房間的大理石牆上，刻著一些傳神的圖案，在這面牆的最上面刻著
一團熊熊的聖火，在聖火的下方站著一個人，而在這一人下面有許多人向
他模拜著，使人有一種君臨天下的感覺． 

LONG);

  set("exits", ([ /* sizeof() == 3 */
	"north" : "/open/prayer/room/punch1-8",		//`大廳
	"south" : "/open/prayer/room/punch1-14",	//`大廳
	"east" : "/open/prayer/room/punch1-10",		//`大廳

]));
  set("light_up", 1);

  setup();
}
 
