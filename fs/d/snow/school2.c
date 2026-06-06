// Room: /d/snow/school2.c

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "過去時空 淳風武館教練場");
  set ("long", @LONG
你現在正站在一個寬敞的教練場中﹐地上鋪著黃色的細砂﹐許多人
正在這裡努力地操練著﹐北邊是一間高大的兵器廳﹐往東則是武館師父
們休息的大廳。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "west" : (: look_door,     "west" :),
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/trainee" : 3,
  __DIR__"npc/fist_trainer" : 1,
]));
  set("outdoors", "snow");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"school1",
  "north" : __DIR__"weapon_storage",
  "east" : __DIR__"schoolhall",
]));

  setup();
}
