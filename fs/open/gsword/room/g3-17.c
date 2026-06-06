// Room: /open/gsword/room/g3-15.c
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
這是通往仙劍七俠寢居的木製走廊, 在這兒聽不到外面的吵雜聲, 有的只是
淡淡得花香, 和和煦的光線。東邊是張乘雲之寢居, 西邊是范松之寢居, 而南邊
正是七俠之首 -- 張乘風之寢居 .

LONG);

  set("exits", ([ /* sizeof() == 4 */
    "west" : "/open/gsword/room/g3-20",
    "north" : "/open/gsword/room/g3-16",
    "south" : "/open/gsword/room/g3-18",
    "east" : "/open/gsword/room/g3-19",
]));

  set("light_up", 1);

  setup();
}
