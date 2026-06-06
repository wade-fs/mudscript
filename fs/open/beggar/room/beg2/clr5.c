// Room: /u/g/guetenr/beggar/room/beg2/clr5.c
inherit ROOM;

void create ()
{
  set ("short", "蒼鬱林道");
  set ("long", @LONG
一彎淺流依傍林道而前，道上不時揚起漫天的風沙，寂靜的林間偶爾傳
來飛禽啼鳴的聲響。一對老牛在青草河畔低頭飲水，放眼所見自有一番恬然
之氣，附近也不見有什麼人家在此居住。眺遠望去只見蜿蜒的林道彷無止盡
的延伸。
LONG);

  set("outdoors", "/open/");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"clr4.c",
  "north" : __DIR__"clr6.c",
]));

  setup();
}
