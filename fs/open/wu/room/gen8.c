inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  seteuid(getuid());    // 不是說要加這一行嗎?
        set("short",HIC + "-四象迷宮陣眼-" + NOR);
        set("long", @LONG
這裏是陣法的中心，只見眼前一亮所有四象迷宮的幻象都消失了，
壁上的夜明珠將這裏照亮的十分光彩亮麗。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/wu/room/gen7",
  "down" : "/open/wu/room/gen9",
]));
  set("light_up", 1);
  set("no_transmit",1);
  set("no_auc",1);
  set("need_key/south",1);
  create_door("south",HIR + "紅色鐵門" + NOR,"north",DOOR_LOCKED);
  set("objects", ([ /* sizeof() == 1 */
]));
  setup();
}
