// Room: /open/capital/room/wulaih.c
inherit ROOM;

void create ()
{
  set ("short", "無賴窩");
  set ("long", @LONG
這裡是個髒亂的地方, 很難想像在京城裡也有這種汙濁的地區,
你向四周一看, 便可發現還有不少人或躺或坐的靠在牆壁上, 雙眼斜
視著你, 嗯~~沒事還是不要在這兒逗留才好。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/capital/room/r39",
  "north" : "/open/capital/room/wulaih2",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/capital/npc/wulai" : 1,
  "/open/capital/npc/dipi" : 1,
]));
  set("light_up", 1);

  setup();
}
