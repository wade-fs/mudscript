// Room: /open/poison/room/room4
inherit ROOM;

void create ()
{
  set ("short", "木屋");
  set ("long", @LONG
這是一間小木屋，裡面只放置了幾樣的家具，看來十分
的簡漏，牆上則掛了幾把斧頭 (axe)，看來這應該是樵夫的
家吧。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "axe" : "大部分斧頭都已生鏽，不堪使用了。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road3",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/poison/npc/son.c" : 1,
  "/open/poison/npc/woodcutter.c" : 1,
]));

  setup();
}
