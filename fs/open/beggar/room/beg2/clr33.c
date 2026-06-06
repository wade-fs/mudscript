// Room: /u/g/guetenr/beggar/room/beg2/clr33.c
inherit ROOM;

void create ()
{
  set ("short", "走道");
  set ("long", @LONG
兩旁掛滿太湖風光景色的畫圖，如幻似真，你靜靜的觀賞
著每一幅圖，慢慢的你也融入畫中，就像是你現在正坐在太湖
旁觀賞景色一樣，看了許久，你不禁嘖嘖稱讚，丐幫中竟然也
有這繪畫奇才。
LONG);

  set("outdoors", "/open/beggar");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"clr34.c",
  "west" : __DIR__"clr32.c",
]));

  setup();
}
