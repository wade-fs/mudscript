// Room: /u/d/dhk/questsfan/room19
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "紫晶層");
  set ("long", @LONG
這一層位於谷間的結晶都呈現紫色的光芒，而這一層
的結晶有一特別的名稱〝皇晶石 〞，因為古代紫色就有著
代表皇帝的極尊、權貴的色澤。另你忽覺不適，直認為你
不應褻瀆此聖地。你一路觀看過延途一層層各式各色的晶
石，另你感到致身於仙境中的感覺、眼花撩亂，忽而好極
忽而鬱悶…變的多愁善感。

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"room18",
  "southdown" : __DIR__"room20",
]));

  setup();
}
