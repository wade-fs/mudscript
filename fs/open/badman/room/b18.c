// Room: /open/badman/room/b18
inherit ROOM;

void create ()
{
  set ("short", "惡人谷南街");
	set( "build", 1 );
  set ("long", @LONG
熱鬧依舊的街道。這裡雖說是與世隔絕，可是該有的都有。小
販的么喝聲此起彼落；而行人雖多腳步匆匆，不過人人摩肩擦踵的
擁擠模樣，與外界相比，也是自成另一個天地。

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/badman/npc/chi_un.c" : 1,
  "/open/badman/npc/e.c" : 1,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"b19",
  "east" : __DIR__"b17",
]));

  setup();
}
