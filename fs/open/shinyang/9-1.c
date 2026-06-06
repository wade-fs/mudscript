// Room: /u/w/whatup/area/shinyang/1-1.c
inherit ROOM;

void create ()
{
  set ("short", "烽火臺");
  set ("long", @LONG
這是襄陽城警戒的烽火臺，當有外敵來犯時，便會點燃這個烽火
臺，通知其他的城鎮戒備，是一個既古老卻十分有效的通訊設備四州
許多衛兵守護著個地方，看你一靠近便想驅趕你走！
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"9-2.c",
  "west" : __DIR__"8-1.c",
]));
  set("no_auc", 1);
  set("outdoors", "/open");

  setup();
}
