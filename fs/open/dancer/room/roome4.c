// Room: /open/dancer/room/roome4.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short",BLU + "寢室" + NOR);
  set ("long", @LONG
這裡是月牙兒的寢室月牙兒平日都是在此休憩，而弟子們若非有
要事也都盡可能的不進此房間打擾她，因此這個房間通常都是寧靜的
適合瞑坐沉思。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" :"/open/dancer/room/roome3.c",
]));
       
        set("item_desc", ([ /* sizeof() == 1 */
  "west" : (: look_door,     "west" :),
]));
  create_door("west",MAG + "雕花紫檀木門" + NOR, "east", DOOR_CLOSED);
  set("light_up", 1);

  setup();
}
