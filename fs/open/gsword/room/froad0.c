#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "叉路口");
	set( "build", 12 );
  set ("long", @LONG
這裡是蜀山小徑的叉路口,往西是七星塔,往南是昆明湖,向東
可到蜀中城,往北則通往森林一片...
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/mob/visitor" : 1,
  "/open/gsword/mob/sells2" : 1,
]));
  set("outdoors", "/open/gsword");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lake1.c",
  "west" : __DIR__"towerf.c",
  "north" : __DIR__"su-main",
  "east" : __DIR__"froad1.c",
]));

  setup();
}
