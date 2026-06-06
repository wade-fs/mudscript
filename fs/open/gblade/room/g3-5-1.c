#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "臥房");
  set ("long", @LONG

剛至房中，便有一股細細的甜香，房中如雪洞一般，一色的玩器全無；案
上只有一個土定瓶，瓶中供著數枝菊，並兩部書，茶壺，茶杯而已；床上
只弔著青紗帳幔，衾褥也十分樸素。傳聞王家大小姐喜好素淨，看這裡的
擺飾，傳聞並不假。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "east" : (: look_door,     "east" :),
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"g3-5",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/leing.c" : 1,
]));
  set("light_up", 1);

	create_door("east","雕花紫檀木門","west",DOOR_CLOSED);
  setup();
}
