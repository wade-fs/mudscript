// Room: /u/d/dhk/questsfan/room12
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "紅晶層");
  set ("long", @LONG
這一層位於谷口的結晶都呈現紅色的光芒，所以顧名
思義這一層的結晶叫〝紅晶石 〞，其顏色通體紅透，似一
泓將溢出的鮮血一般。你一路觀看過延途一層層各式各色
的晶石，另你感到致身於仙境中的感覺、眼花撩亂，心情
頓時開朗許多。


LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room11",
  "north" : __DIR__"room13",
]));

  setup();
}
