// Room: /open/ping/room/road11
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
  set ("long", @LONG
這裡是平南城的住宅區,人群也稀少多了,一片淡淡的祥和漫
布在空氣裡,不知是誰家的小孩傳來陣陣的嘻鬧聲,一隻野狗在路
上漫步著,注視著你這異鄉的遊客.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road12",
  "north" : __DIR__"road9",
]));
  set("outdoors", "/open/ping");

  setup();
  replace_program(ROOM);
}
