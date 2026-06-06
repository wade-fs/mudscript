// Room: /open/poison/room/room20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set ("short", "牢房");
  set ("long", @LONG
這裡是冥蠱魔教用來囚禁一般囚犯的地牢，地上則是鋪
上了一層雜亂無序的稻草，你感到這裡是那麼的髒亂，一刻
也不願再多停留，恨不得早點離開。
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"path13",
]));
  set("objects", ([ /* sizeof() == 1 */
	"/open/poison/npc/yun" : 1,
]));
  set("need_key/north",1);
  create_door("north",HIR"紅色鐵門"NOR,"south",DOOR_LOCKED);
  setup();
}
