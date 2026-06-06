// Room: /u/s/sueplan/newplan/area/f10.c
inherit ROOM;

void create ()
{
  set ("short", "雲山山中");
  set ("long", @LONG
你隨著盤巒山徑登上雲山，滿眼挺拔蒼松高聳入雲，山風徐來松林低吟
，透著幾分灑脫泰然；路邊潺潺的山澗，如一泓白練款款流動，水聲叮呤如
間關鶯語，讓你忍不住趨前掬起一捧飲下，清冽的山泉沁透心房，讓你倦意
全消，精神抖擻地登上山路。
LONG);

  set("outdoors", "/u/s");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"f9",
  "north" : __DIR__"f11.c",
]));

  setup();
}
