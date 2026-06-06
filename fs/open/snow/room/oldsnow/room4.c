#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "雪蒼山山腰");
  set ("long", @LONG
這裡是雪蒼山的山腰﹐遠遠往上望去﹐紫雲寶殿就在不遠的地方
聽說山上的雪蒼派是武者工會的所在地﹐在此常常可以看到來來往往
的武者及想成為武者的人們。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room5_out",
  "down" : __DIR__"room3",
  "west" : __DIR__"go7",
]));

   set("light_up",1);
  set("objects",([ "/open/snow/npc/snow_guard" : 6 ]));

  setup();
}
void init()
{
}
int valid_leave( object me , string dir )
{
	if( dir != "up" ) return 1;
	if( present("snow guard",this_object()) ) {
		tell_object(me,"雪蒼武者攔住了你的去路。\n");
		return 0;
	}
	return 1;
}
int do_search()
{
	if(this_player()->query("family/family_name")!="雪蒼派")
		return 0;
	this_player()->set_temp("have_search_8",1);
	tell_object(this_player(),"你在此尋找﹐發現一個暗門(key)。\n");
	return 1;
}
int do_push(string str)
{
	if(str!="key") return notify_fail("你想推什麼 ?\n");
	if(this_player()->query_temp("have_search_8")!=1)
		return notify_fail("你找不到八卦陣的暗門。\n");
	this_player()->delete_temp("have_search_8");
	tell_object(this_player(),"只聽見「喀」的一聲﹐出現一條密道﹐你從密道通到八卦陣的出口。\n");
	this_player()->move(__DIR__"room5_out");
	return 1;
}
