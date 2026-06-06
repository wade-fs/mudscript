// Room: /open/capital/room/r01.c

inherit ROOM;

void create ()
{
  set ("short", "西城門下");
  set ("long", @LONG
這裡是進出城的通道, 由於京城防守嚴密, 因此常有軍隊通行，所
以你還是要小心點, 免的惹禍上身。路上的石板也因為軍隊移動頻繁,
而磨的有點老舊。
    東方的大道通往皇宮大門, 也可連至京城裡最富裕的區域。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/soldier" : 1,
]));

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/capital/room/D01",
  "east" : "/open/capital/room/r02",
]));

  set("gopath", "east");

  setup();
}
