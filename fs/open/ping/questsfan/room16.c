// Room: /u/d/dhk/questsfan/room16
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "綠晶層");
  set ("long", @LONG
這一層位於谷緣的結晶都呈現綠色的光芒，所以這一
層的結晶有一特別的名稱叫〝玉晶石 〞，因它散發著比最
高級的玉更綠更剔透的光澤。你一路觀看過延途一層層各
式各色的晶石，另你感到致身於仙境中的感覺、眼花撩亂
，心情頓時開朗許多。

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"room17",
  "eastup" : __DIR__"room15",
]));

  setup();
}
