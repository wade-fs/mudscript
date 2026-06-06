inherit ROOM;

void create ()
{
  set ("short", "l高塔");
  set ("long", @LONG
這裡有一座高聳入雲的塔,塔上刻著斗大的兩個大字"妖塔",這
裡想必是天龍寺三禁地之三--"三塔"的其中之一,不過在這裡卻看
不到進去的入口,真是令人疑惑。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"aa45",
  "northwest" : __DIR__"aa46",
  "southwest" : __DIR__"aa47",
  "southeast" : __DIR__"aa48",
]));
}
