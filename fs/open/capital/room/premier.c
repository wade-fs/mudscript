// Room: /open/capital/room/premier
inherit ROOM;

void create ()
{
  set ("short", "丞相府前庭院");
  set ("long", @LONG
踏進了丞相府門口, 是一處庭院, 流水假石, 草木扶疏, 水聲淙淙
, 簡直巧奪天工, 另你嘆為觀止, 中間的一條路直直的通往一棟屋子的
大門。這裡的設計便是皇宮裡的工匠親自量造的, 聽說是皇上特地命人
如此的, 由此可知當今宰相是如何受到皇上愛惜。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/capital/room/r63",
]));

  setup();
}
