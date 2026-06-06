// /u/j/judd/room/r13.c
inherit ROOM;

void create ()
{
  set ("short", "中堂西側");
  set ("long", @LONG
這裡是中堂的角落，也是通往火室圖書館的必經道路，地上有一
條紅色的道路一直通往西北，東邊則可通往後廳休息處，火室圖書館
到底是放些什麼書呢？這個問題，只有自己去看看才知道，只要沿著
那條紅色的路就可以了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r16.c",
  "northwest" : __DIR__"r10.c",
]));
  set("light_up", 1);

  setup();
}
