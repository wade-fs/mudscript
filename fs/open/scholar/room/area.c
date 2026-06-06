// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "青石小徑");
  set ("long", @LONG
這是通往儒門房舍間唯一的一條青石小徑，小徑的
南方是儒門的大門，而小徑的四周有著許許多多的草坪
，在草坪的四周常可以看到儒生們在一旁讀書及研究兵
法，過得十分的愜意。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"area_3.c",
  "north" : __DIR__"area2.c",
  "south" : __DIR__"r24.c",
  "east" : __DIR__"area_1.c",
]));

  setup();
}
