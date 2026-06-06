// Room: /open/capital/room/h14.c

inherit ROOM;

void create ()
{
  set ("short", "蘿蔔胡同");
  set ("long", @LONG
你看到有一群小孩子正蹲在門口, 聚精會神的不知道在觀察什麼東
東, 好奇的走過去一看, 原來是....不提也罷。小孩子就是小孩子。除
此之外, 你發現到這兒的空氣清新, 不禁深深的吸了幾口氣。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"h13",
  "east" : __DIR__"h15",
]));
  set("outdoors", "/open/capital");

  setup();
}
