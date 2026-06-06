// Room: /open/poison/room/room3
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "獵戶");
	set( "build", 13 );
  set ("long", @LONG
這是一個獵人的家，牆壁上掛了一把製作精細的大弓，
旁邊放置一筒鳳尾金箭，看樣子這個獵人的臂力必定是強而
有力，此外尚掛了一張純白虎皮，室內則擺有幾張精簡的桌
椅，是一個相當清淨的房間。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
  "south" : __DIR__"road3",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/hunter" : 1,
]));

  setup();
}

int valid_leave(object me, string dir)
{
	object who;
	if ( dir == "west" && who = present("hunter", environment(me)) )
	     if(me->query("class") != "poisoner")
		return notify_fail(HIC"獵人怒道﹕想私闖民宅呀!!\n"NOR);
	return ::valid_leave(me, dir);
}
