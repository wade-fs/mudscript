// Room: /u/r/ranko/room/pa1.c
inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
這是一條彎彎曲曲的小路，路上石子不少，踩在腳底怪不舒服
的，不時還得注意地上以免被拌倒了，兩旁雜草叢生，似乎欠缺人
來打理。西邊通往農田，東邊則通往晒穀場，往北走則是一間土地
公廟。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/child.c" : 2,
]));
  set("outdoors", "/open/poison");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"f8.c",
  "south" : __DIR__"pa2.c",
  "east" : __DIR__"pl8.c",
]));

  setup();
}
