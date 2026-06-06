inherit ROOM;
void create()
{
  set ("short","叉路");
  set ("long",@LONG
這裡是一條叉路 ,道路在這裡向東西兩個不同的方向延伸 .東邊是
一間破舊的草屋 ,而西邊則是道路的延伸 .
LONG);

  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"wolf10.c",
  "east" : __DIR__"wolf09.c",
  "south" : __DIR__"wolf07.c",
]));

  set("objects",([ /* sizeof() == 2 */
  "/open/badman/npc/wolf02.c" : 2,
]));

  setup();
}
