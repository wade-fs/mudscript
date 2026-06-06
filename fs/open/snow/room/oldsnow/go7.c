#include <room.h>
#include <ansi.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","古奇鋒");
  set ("long", @LONG
這裡是雪蒼山中的一處聖景﹐名為「古奇峰」
在此遠眺峰下﹐則大地萬物盡在眼中﹐
令人不免懷疑自己是否來到人間仙境。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/snow/room/oldsnow/room4",
]));


   set("light_up",1);


  setup();
}
void init()
{
}
int do_abandon( string arg )
{
 object me = this_player();
	if( !arg || arg != "seckee" ) return 0;
	me->delete("sec_kee");
	me->delete("max_s_kee");
	return notify_fail("你放棄了你身上的靈氣。\n");
}
int do_use( string arg )
{
	object ob;
 object me = this_player();
	if( !arg || arg != "de" ) return 0;
	if( !(ob=present("de",this_player())) ) return 0;
	message_vision("$N在這裡吹奏了青龍之笛 .......\n",this_player());
	if( me->query("sec_kee") ) 
		return notify_fail("你的身上已經有一道靈氣了﹐以致青龍不能接近﹐若你要放棄靈氣可(destruct seckee)。\n");
	message_vision(HIG "突然間在天空的雲際中竄出了一條青龍﹐這條青龍直接奔入$N的體內﹐形成了青龍之氣。\n",this_player());
	me->set("quests/dragon-kee",1);
	me->set("sec_kee","dragon");
	me->set("max_s_kee",20);
	me->set("s_kee",20);
	destruct(ob);
	return 1;
}
