// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "青石小徑");
  set ("long", @LONG
這是通往儒門房舍間唯一的一條青石小徑，小徑的
北邊可以進入儒門內堂，小徑的四周有著許許多多的草
坪，在草坪的四周常可以看到儒生們在一旁讀書及研究
兵法，過得十分的愜意。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"in.c",
  "west" : __DIR__"area_4.c",
  "south" : __DIR__"area.c",
  "east" : __DIR__"area_2.c",
]));

  setup();
}
