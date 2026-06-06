inherit ROOM;

void create()
{
  set("short", "密室");
  set("long", "往前走了數十步，密閉的空間，不流通的空氣，使你的氣息
微微散亂。這裡的風砂更為猛烈，微塵飛舞，使你不得不瞇著眼
睛。由你身上所發出的火光更是漂浮不定，彷彿隨時都會熄滅般
。通道的盡頭看來就在前面。
");

  set("exits", ([ /* sizeof() == 2 */
  "forward" : __DIR__"d_c03.c",
  "back" : __DIR__"d_c01.c",
]) );

  set("light_up",-1);

setup();
}
