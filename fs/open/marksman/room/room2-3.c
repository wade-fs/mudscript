// Room: /open/marksman/room/room2-1
inherit ROOM;

void create ()
{
  set ("short", "草原");
  set ("long", @LONG
一望無際的大草原，身旁的草長的都比人還高了，
    草中還有少許小動物，跑來跑去的，走起路來
    可要小心一點囉。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2-4",
  "east" : __DIR__"room2-2",
]));
  set("outdoors", "/open/marksman");

  setup();
}
