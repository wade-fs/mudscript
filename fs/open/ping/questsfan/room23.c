// Room: /u/d/dhk/questsfan/room23
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "菱晶層");
  set ("long", @LONG
這一區的結晶就沒有顏色了，皆呈現透明且各晶石的
菱角會閃爍著些許的微光。而且延途的結晶都呈不規則又
菱菱角角的形狀，與之前色彩繽紛、燦爛有著天差地遠的
差異。其反映出多變、出奇之氣質。若硬要形容它，那我
只能用〝變〞這一個字來形容。

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room22",
  "east" : __DIR__"room24",
]));

  setup();
}
