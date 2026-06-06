// Room: /u/d/dhk/questsfan/room27
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "虹晶匯靈地");
  set ("long", @LONG
你一進入洞穴的同時，忽覺華光萬道好似洞外的景
緻色彩都被吸納、濃縮到了這兒一般。這裡的晶石所透
射散發出的光芒就如同谷外那座晶橋一樣。但願這兒的
晶石確好似附有魔力一般引響著你。在這兒有如躺臥在
陽光下般的溫暖，冰涼的微風徐徐的吹拂著你，但是此
地明明是谷底呀？怎會有如此現象…

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"room26",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/stone.c" : 1,
]));
  set("no_transmit", 1);
  set("no_clean_up", 1);

  setup();
}
