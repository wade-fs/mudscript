// Room: /open/ping/room/road9
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
  set ("long", @LONG
這裡是平南城的住宅區,人群也稀少多了,一片淡淡的祥和漫
布在空氣裡,不知是誰家的小孩傳來陣陣的嘻鬧聲,一隻野狗在路
上漫步著,注視著你這異鄉的遊客.
LONG);

  set("objects", ([ /* sizeof() == 1 */
"/open/center/npc/dog" : 1,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"road11",
  "north" : __DIR__"road8",
  "west" : __DIR__"soldier1.c",
  "east" : __DIR__"inn.c",
]));

  setup();
}
