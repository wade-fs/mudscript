//open/prayer/room/punch1-12

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇大聽");
  set ("long", @LONG

    你嚇了一跳!!因為你以為角落有一條巨龍要吃了你，卜一定神一看，
在角落的那條巨龍，原是支撐總壇宮殿的四支盤龍大柱，就因為上的刻工
太栩栩如生了，才會使人產人幻覺． 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/major-officer" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/prayer/room/punch1-9",		//`大廳
	"west" : "/open/prayer/room/punch1-13",		//`大廳

]));
  set("light_up", 1);

  setup();
}
 
