// Room: /open/gsword/room/nghouse.c
inherit ROOM;

void create ()
{
  set ("short", "大長廊");
  set ("long", @LONG
這兒的長廊跟西面的比起來顯的又寬的多了，兩側的牆壁上滿是當年
仙劍派的開山祖師〔逍遙子〕大戰群魔的情景，看著祖師爺身形飄忽，一
隻木劍在手中竟能使的如此渾圓如意，看的你心炫神怡。北邊有個大廣場
。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/gsword/room/g1-3.c",
  "north" : "/open/gsword/room/g2-12.c",
]));

  set("light_up", 1);

  setup();
}
