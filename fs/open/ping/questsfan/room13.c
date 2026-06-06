// Room: /u/d/dhk/questsfan/room13
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "橘晶層");
  set ("long", @LONG
這一層位於谷口的結晶都呈現橘色的光芒，所以顧名
思義這一層的結晶叫〝橘晶石 〞，此地的氣氛、光芒使你
有如春天百花盛開的感覺，心情洋溢著春風。你一路觀看
過延途一層層各式各色的晶石，另你感到致身於仙境中的
感覺、眼花撩亂，心情頓時開朗許多。

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room12",
  "north" : __DIR__"room14",
]));

  setup();
}
