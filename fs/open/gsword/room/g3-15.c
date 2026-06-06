// Room: /open/gsword/room/g3-15.c
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
這是通往仙劍七俠寢居的木製走廊, 在這兒聽不到外面的吵雜聲, 有的只是
淡淡得花香, 和和煦的光線。東邊是仙劍一隻花 --- 何雙雙的寢居, 西邊則是仙
劍老七李逍遙之寢居 , 當然他們都忙著自個兒的事, 很少會在寢居內做白日夢的 ..

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/gsword/room/g3-24.c",
  "north" : "/open/gsword/room/g3-12",
  "south" : "/open/gsword/room/g3-16.c",
  "east" : "/open/gsword/room/g3-23.c",
]));

  set("light_up", 1);

  setup();
}
