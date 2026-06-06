#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "火龍幻界--黃色結界");
  set ("long", @LONG
來到此地, 你往四周探了探, 這裡的環境跟剛才你看到的地方不太一樣
. 地上畫了許多奇形怪狀的圖案, 更奇特的是, 上方竟有一道黃色光芒照射
著這裡, 你不禁感到驚奇, 在如此的地方竟有類似極光的景象, 真令你大開
眼界。
LONG);

  set("outdoors", 1);
  set("no_transmit",1);
  set("no_chome",1);
  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"f-4.c",
  "west" : __DIR__"f-14.c",
  "southwest" : __DIR__"f-16.c",
  "east" : __DIR__"f-21.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/fire-hole/npc/dragon-y.c" : 1,
]));

  setup();
}
void init()
{
   if(!present("yellow dragon"))      this_player()->delete_temp("fight_yellow");
}

int start()
{
        object room = this_object();
        call_out("del",1800,room);
        return 1;
}

int del(object room)
{

        room = this_object();
        room->delete("no_reset");
        return 1;
}
