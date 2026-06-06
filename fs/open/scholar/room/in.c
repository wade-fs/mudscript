// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "內堂大廳");
  set ("long", @LONG
這裡是儒門的內堂，兩旁放置著許許多多的
桌椅，桌上放置著文房四寶，只見許多的初級的
儒生正在討論著論語，只見北方是儒門的中堂，
東西兩邊是初級儒生們夜間休息的臥房。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"area2.c",
  "west" : __DIR__"in3.c",
  "north" : __DIR__"r20.c",
  "east" : __DIR__"in2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/fall.c" : 1,
]));

  setup();
}
