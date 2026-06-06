// Room: /u/m/moner/open/room/r13.c 
inherit ROOM;
#include <room.h>
#include <ansi.h>
 
void create ()
{
  set ("short", "大門口");
  set ("long", @LONG

    你正處於風行山寨大門前, 隔著鏤花白濱鐵大門, 你可以看到
院子裡花木扶疏, 綠油油的大草坪隨地展開, 有噴泉流水, 蝶蜂飛舞,
稍遠處老樹拔地而起, 形成處處的綠陰, 正是庭院深深, 好景處處,
濱鐵大門是關著的, 你可以試著打開它(open door).


LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r15.c",
  "north" : __DIR__"r12.c",
]));
create_door("north",HIW"白鐵濱花門"NOR,"south",DOOR_CLOSED);

  setup();
}
