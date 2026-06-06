// Room: /open/gsword/room/g3-3.c
inherit ROOM;

void create ()
{
  set ("short", "儲藏室");
  set ("long", @LONG
這是仙劍派堆放雜物的儲藏室 ,你看到一個個箱子整齊的排放在房
子四周 ,箱子及地上鋪滿了一層厚厚的灰塵 ,似乎甚少人來此 .

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/gsword/room/g3-2",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/obj/map1" : 1,
]));
	set("light_up",1);

  setup();
}
