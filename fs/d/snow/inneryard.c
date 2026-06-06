// Room: /d/snow/inneryard.c

inherit ROOM;

void create ()
{
  set ("short", "過去時空 天井");
  set ("long", @LONG
這裡是淳風武館中的天井﹐往西走可以回到正廳﹐往北邊是書房﹐
南邊是招待客人的廂房﹐往東一條長廊通往武館內院﹐天井中種滿了許
多奇花異草﹐中央立著一根石柱(pillar)﹐上面似乎刻著字。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "pillar" : "石柱上刻著﹕劍氣指天、劍心內斂、劍芒不顯、劍神如電。
",
]));
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"schoolhall",
  "north" : __DIR__"nyard",
  "south" : __DIR__"guestroom",
  "east" : __DIR__"innerhall",
]));
  set("outdoors", "snow");

  setup();
}
