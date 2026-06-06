// Room: /open/gsword/room/eghouuse3.c
inherit ROOM;

void create()
{
  set ("short", "寢居");
  set ("long", @LONG
這兒是輩分較高的師兄們所住的地方，只見一張張的床排列的非常整齊
，床上的被褥，衣物等更是折疊的方方正正，顯見仙劍紀律之嚴，更顯
仙劍弟子的心性不訶。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"eghouse4",
  "north" : __DIR__"eghouse2",
]) );

  setup();
}
