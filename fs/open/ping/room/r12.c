// Room: /u/m/moner/open/room/r12.c 
inherit ROOM;
#include <ansi.h>
#include <room.h>
 
void create ()
{
  set ("short", "庭園");
  set ("long", @LONG

    走進園內, 愈發的感到幽靜, 淡淡的草香撲面而來, 豔陽, 微風,
綠蔭, 構成了一幅風景畫, 十二棵大橡樹排成一列, 像是歡迎你的來到
, 隨著橡樹大道望去, 風行山寨主建築物就在大道盡頭, 一坐噴泉正吐
出盈盈水柱,在陽光下正顯得晶瑩.


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r11.c",
  "south" : __DIR__"r13.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
  set("outdoors", "wind");
create_door("south",HIW + "白鐵濱花門" + NOR,"north",DOOR_CLOSED);

  setup();
}
