//road1.c
inherit ROOM;

void create ()
{
  set ("short", "雙龍道");
  set ("long", @LONG
昏暗的密道，兩壁繪著兩條栩栩如生的龍，黑暗中..你發現龍的雙眼正盯著你看...
此處次乎只有一個出口..看樣子..你只能乖乖的往前方走了....。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/gsword/room2/road2",
]));
  set("no_magic", 1);
  set("no_transmit", 1);
  set("no_fight",1);
  setup();
}
