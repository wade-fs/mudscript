// Room: /open/poison/room/room21
inherit ROOM;
#include <ansi.h>
#include <room.h>
void create ()
{
  set ("short", "牢房");
  set ("long", @LONG
這裡空空盪盪的，當鐵門關上時，裡面一片死寂，聽不
到外面任何一絲聲音，四周牆壁上掛滿了各式各樣的刑具，
地上留有斑斑舊血跡，這裡該是魔教用來刑囚的地方吧。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "west" : (: look_door,     "west" :),
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room22.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/wine.c" : 1,
]));
  create_door("west",HIY "黃色鐵門"NOR, "east", DOOR_CLOSED);
  set("need_key", ([ /* sizeof() == 1 */
  "west" : 1,
]));

  setup();
}
