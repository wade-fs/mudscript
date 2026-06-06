inherit ROOM;

void create ()
{
  set ("short", "右側走廊");
  set ("long", @LONG
從這裡往北走就是天龍寺的大雄寶殿了,從遠方看起來大雄寶殿可
是十分莊嚴雄偉,然而近看才發現樑柱可是雕刻得非常細膩,真可說是
建築藝術中的極品。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"aa37",
  "south" : __DIR__"aa32",
]));
}
