// Room: /open/main/room/s16.c
#include "/open/open.h"
inherit ROOM;
string do_bush();
void create()
{
	set("short", "草原");
	set( "build", 24 );
	set("long", "這裡是一片草原，割人的野草凌亂的長著，高高低低的芒
穗隨著風起伏，周圍還有一團不小的樹叢，這裡應該有不少動物躲藏。
");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s20",
  "north" : __DIR__"r15",
  "west" : __DIR__"s15",
  "east" : __DIR__"s17",
]) );
  
  set("item_desc", ([ /* sizeof() == 1 */
  "bush" : "雜亂的植物生長在一起, 看起來蠻平常的。\n",
  ]));
  set("search_desc",([
  "bush" : (: do_bush :),
  ]));
  set("outdoors", "/open/main" );

  setup();
}

string do_bush()
{
	object me=this_player();
	if(me->query_temp("thief") == 8)
	{
	  write("這樹叢被你挖啊挖的......\n\n哇..怎麼有一個大洞..你跌了進去....\n"+
	  "..................\n..................\n..................\n");
	  tell_room(environment(me),"啊~~~~~~~~的一聲慘叫, "+me->query("name")+"已不見人影。\n",me);
	  me->move(CAPITAL_ROOM"q0");
	  return("咚的一聲..你掉到了地上。\n");
	}
	else
	  return("你找了老半天，可是看不出有任何特殊之處。\n");
}	  
	
