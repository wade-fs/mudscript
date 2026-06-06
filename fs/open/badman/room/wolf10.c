inherit ROOM;
void create()
{
   set ("short","小道");
  set ("long",@LONG
這裡是這個村莊最大的一條道路 ,來到這裡 ,狼隻已不復見 ,在你
的西邊是一棟民房 ,往北則是道路的延伸 .
LONG);

  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"wolf11.c",
  "east" : __DIR__"wolf08.c",
  "north" : __DIR__"wolf12.c",
]));

  setup();
}
