//open/prayer/room/1elder5

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "傳功\長老房");
  set ("long", @LONG

	    這裡又有一位弟子，正一股腦的坐在地上
	發呆，不知是練武遇到瓶頸，還是正在打混摸
	魚，看來是在等傳功長老的樣子．

LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/1elder6",		//`長老房
	"east" : "/open/prayer/room/1elder2",		//`長老房
]));
 set("light_up", 1);

  setup();
}
 
