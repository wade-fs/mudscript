// Room: /open/gsword/room/gsword1-5.c
inherit ROOM;

void create ()
{
  set ("short", "武器室");
  set ("long", @LONG
這裡是仙劍派的武器儲藏室 ,左首一排長架擺滿了各式各樣的劍 :長劍 ,
短劍 ,細劍 ,竹劍 ...等 ,一應俱全 ,就只差沒有寶劍 .右首的長架則擺滿
了其它各式各樣的武器 ,不論是大刀 ,鐵棍 ,長鞭 ,短匕 ,暗器 ,盡皆齊備.

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/gsword/room/g1-6.c",
]));
  set("objects", ([ /* sizeof() == 3 */
  "/open/gsword/obj/woodsword" : 1,
  "/open/gsword/obj/chusword" : 2,
  "/open/gsword/npc/trainee-4" : 1,
]));

  setup();
}
