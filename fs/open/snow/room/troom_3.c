// Room: /u/e/eiei/work/troom_3.c
inherit ROOM;

void create ()
{
  set ("short", "叉路");
  set ("long", @LONG
    走過滿是奇花異草的小路之後，到了這一處叉路。
    向東北方望去，很明顯的可以發現其中有一棵樹長的比
    其他的樹木還要高大。而再往上爬的話自然可以到達更
    高的山頂，不過此處之後的山路崎嶇難行，一般人平常
    最多只是到這裡賞賞風景而已。
    路旁貼著一張佈告(sign)
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "    警告：山中常有異獸出沒，無事者請不要逗留。
",
]));

  set("outdoors", "/u/e/eiei/work");

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"troom_2.c",
  "eastup" : __DIR__"troom_3a.c",
]));

  setup();
}
