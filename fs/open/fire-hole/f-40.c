//增加玩家是否存在(離線)的判定 by blazakira 2011/10/19

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "火龍幻界--白色結界");
  set ("long", @LONG
來到此地，你往四周探了探，這裡的環境跟剛才你看到的地方不太一樣
。地上畫了許多奇形怪狀的圖案，更奇特的是，上方竟有一道紫色光芒照射
著這裡，你不禁感到驚奇，在如此的地方竟有類似極光的景象，真令你大開
眼界。
LONG);

  set("outdoors", 1);
  set("no_transmit",1);
  set("no_chome",1);
  set("exits", ([ /* sizeof() == 4 */
    "northeast" : __DIR__"f-32.c",
    "west" : __DIR__"f-39.c",
    "southwest" : __DIR__"f-46.c",
    "east" : __DIR__"f-41.c",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    "/open/fire-hole/npc/dragon-w.c" : 1,
  ]));
  setup();
}

void init()
{
  object me=this_player();
  if(me && !present("white dragon")) me->delete_temp("fight_white");
}

int start()
{
  object room = this_object();
  call_out("del",1800,room);
  return 1;
}

int del(object room)
{
//  room = this_object();
  room->delete("no_reset");
  return 1;
}
