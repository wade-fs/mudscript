// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "草坪");
  set ("long", @LONG
這是位著青石小徑旁的草坪，草坪上開著許許多多的
花草，看起來十分的舒服，草坪的上面坐著許多的儒門弟
子，他們一面研究兵法，一邊觀看小徑上的來客。
LONG);

  set("have_reborn", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/new_scholar2.c" : 2,
]));
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"backm1",
  "east" : __DIR__"area2.c",
  "south" : __DIR__"area_3.c",
]));

  setup();
}
