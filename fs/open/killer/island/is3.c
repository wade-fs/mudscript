// Room: /u/u/unfinished/room/is3.c
inherit ROOM;

void create ()
{
  set ("short", "小島南岸");
  set ("long", @LONG
小島的最南端, 西邊是高聳的石丘, 東邊是船隻擱淺的地方, 西北邊有一片
樹林, 感覺十分陰森. 此地十分空曠, 便地只有些許的碎小岩石. 南邊海面上看
得到零星突出的礁石, 也難怪船隻被風浪衝到此地船底會損毀.
LONG);

  set("outdoors", "/u/u");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"is4.c",
  "west" : __DIR__"is2",
]));

  setup();
}
