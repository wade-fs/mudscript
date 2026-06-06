//增加ppl exp偵測，房止ppl利用follow溜進來
//modify by cyw at 91/04/02
#include <ansi.h>
#include "firestorm.c"
inherit ROOM;
void create ()
{
  set ("short", "火龍幻界邊緣");
	set( "build", 12 );
  set ("long", @LONG
這裡是結界的邊緣, 這裡的魔法力就沒那麼的強烈了, 天候溫度跟平
常一樣, 但還未離開幻界的控制範圍, 這裡有一根直達雲際, 十分奇怪的
巨石, 這個也是拿來鞏固結界用的吧! 
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/fire-hole/f-3.c",
  "southwest" : __DIR__"f-2.c",
  "out" : "/open/tendo/kunlun/m3",
]));
  set("outdoors", 1);
  set("no_transmit",1);
  set("no_chome",1);
  setup();
}

int valid_leave(object who, string dir)
{
	if (dir == "southwest" || dir == "southeast")
	{
		if(!who->query_temp("check_ok",1))
		  return notify_fail(HIY + "趕著去死也不用衝這麼快吧!!\n" + NOR);     
	        who->delete_temp("check_ok",1);
        }
        return :: valid_leave(who,dir);
}
