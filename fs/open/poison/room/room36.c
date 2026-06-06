#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "虎居");
  set ("long", @LONG
才一進門你就知道 ,這是一個錯誤的決定 ;爐上燒著一鍋滾燙的
熱油 ,案上放著一把鋒利的大刀 ,白晃晃的刀鋒反映著你的恐懼
 ,一位滿口利牙的老婆婆 ,正露出她那一顆顆白牙 ,對著你露齒
而笑 :~~~~~~

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "out" : (: look_door,     "out" :),
]));
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"room35",
]));
  create_door("out", "木雕門", "enter", DOOR_CLOSED);
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/tiger.c" : 1,
]));
  set("light_up", 1);

  setup();
}
