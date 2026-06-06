// Room: /open/poison/room/path6
inherit ROOM;

void create ()
{
  set ("short", "密道");
  set ("long", @LONG
你發現這裡點點血跡，處處刀痕劍痕的，牆壁上還留下
幾處深深掌印，有些掌印奇黑無比，莫非就是毒掌留下的痕
跡，地上白骨成堆，可想當時戰況是何等的慘烈，心想難不
成這就是號稱『神魔大戰』之役的地方。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/poison/room/path5",
  "north" : "/open/poison/room/path7",
]));

  setup();
}
