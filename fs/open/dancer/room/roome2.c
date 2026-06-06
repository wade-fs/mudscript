// Room: /open/dancer/room/roome2.c :cgy

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
夜夢小築的走廊，北面的牆上有著美麗的雕塑，走到這裡你聞到
陣陣花香，東面的走廊可連接到月牙兒的寢室，南面則是花園，並有
花園小徑可供賞花。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"roome1",
  "east" : __DIR__"roome3",
  "south" : __DIR__"roomes1",
]));
 set("objects", ([ /* sizeof() == 1 */
 "/open/dancer/npc/ggirl.c" : 2,
]));

  set("light_up", 1);

  setup();
}
