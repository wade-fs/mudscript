// Room: /u/s/sueplan/newplan/area/f11.c
inherit ROOM;

void create ()
{
  set ("short", "雲山山中");
  set ("long", @LONG
你隨著盤巒山徑登上依雲山，滿眼挺拔蒼松高聳入雲，山風徐來松林低
吟，透著幾分灑脫泰然；山中昨夜春雨連綿，樹梢凝成雨露瑩亮，紛亂木石
中山泉若隱若現地向下奔流，泉水旁幾株木蘭正發紅萼，素豔風吹膩粉開，
有若淑女嬌態，令人望而生情。
LONG);

  set("outdoors", "/u/s");
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"f12.c",
  "south" : __DIR__"f10",
  "north" : __DIR__"f15.c",
]));

  setup();
}
