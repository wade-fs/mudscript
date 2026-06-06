inherit ROOM;

void create()
{
  set("short", "密室");
  set("long", "剛落得地來，眼前一片暗矇矇地，看不太清楚。你點起身
上可照亮周圍之物，始能看清通道走向。這裡只有一條往前的
路和身後的暗道入口。風砂由前面吹來，看來駱駝的飼養地應
該就在前面不遠處。
");
  
  set("exits", ([ /* sizeof() == 2 */
  "forward" : __DIR__"d_c02.c",
  "out" : __DIR__"d_c.c",
]) );

  set("light_up",-1);

setup();
}
