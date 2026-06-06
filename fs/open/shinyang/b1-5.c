// Room: /u/w/whatup/area/shinyang/b1-5.c
inherit ROOM;

void create ()
{
  set ("short", "刑具間");
  set ("long", @LONG
四周突然亮了起來，熊熊燃燒的火盆放在房間的四周，發出陣陣
的高溫，兩旁的牆上掛滿許的刑具，前方的牆上正吊著兩個人犯低著
頭不知死活，許多個烙鐵正放在火盆中燒烤著，看著通紅的烙鐵令人
頭皮發麻想要趕快離開！
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"b1-3.c",
]));
  set("no_auc", 1);

  setup();
}
