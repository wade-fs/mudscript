inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  seteuid(getuid());    // 不是說要加這一行嗎?
        set("short",HIC + "-八卦迷宮陣眼-" + NOR);
        set("long", @LONG
這裏是陣法的中心，只見眼前一亮各種卦象的幻象都消失了，
壁上的夜明珠將這裏照亮的十分光彩亮麗。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/wu/room/gen18",
  "south" : "/open/wu/room/gen16",
]));
  set("light_up", 1);
  set("no_transmit",1);
  set("no_auc",1);
  set("need_key/north",1);
set("need_key/south",1);
  create_door("south",HIY + "黃色鐵門" + NOR,"north",DOOR_LOCKED);
create_door("north",HIB + "藍色鐵門" + NOR,"south",DOOR_LOCKED);

  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/guard4" : 1,
]));
  setup();
}
