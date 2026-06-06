// Room: /u/d/dhk/questsfan/room11
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "棕晶層");
  set ("long", @LONG
這一層位於谷口的結晶都呈現棕色的光芒，所以顧名
思義這一層的結晶叫〝棕晶石 〞，其材質和谷外的晶橋大
同小異也是一奇石也。霎時你感嘆見聞太少，世上竟有此
奇景、奇珍竟第一次見識。

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room10",
  "east" : __DIR__"room12",
]));

  setup();
}
