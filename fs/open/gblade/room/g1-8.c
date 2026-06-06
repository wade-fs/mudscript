inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG

你從飯廳一路到了這裡，四溢的香氣讓你口水差一點滴出來了。有幾個師
傅正在這裡準備今天的宴席，你想趁師傅不注意偷一些點心，結果一個不
小心被燙到了。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"g1-7",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/cook" : 1,
]));
  set("light_up", 1);

  setup();
}
