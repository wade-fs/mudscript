// Room: /u/d/dhk/questsfan/room20
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "灰晶層");
  set ("long", @LONG
這一層位於谷間的結晶都呈現銀色的光芒，所以顧名
思義這一層的結晶叫〝銀晶石 〞，其耀眼的光芒發散四周
再加上不時閃爍的折射晶光，宛若一片無際的銀河般，配
合著星光幻射著誘人目光的圖畫。另你忽覺不適，直認為
你不應褻瀆此聖地。你一路觀看過延途一層層各式各色的
晶石，另你感到致身於仙境中的感覺、眼花撩亂，忽而好
極忽而鬱悶…變的多愁善感。

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"room21",
  "northup" : __DIR__"room19",
]));

  setup();
}
