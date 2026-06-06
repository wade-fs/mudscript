// Room: /u/r/ranko/room/p1.c
inherit ROOM;

void create ()
{
  set ("short", "晒穀\場");
  set ("long", @LONG
在你眼前的是一大片的空地，這裡是村民收割穀物之後用來放
置穀物接受曝晒的地方，有稻米、小麥、玉黍蜀、蕃薯、以及一些
豆類等等。不時會有一群麻雀及一些不知名的鳥類飛下來偷吃穀物
惹的看守這裡的村民氣呼呼的追趕著，演出一場人獸追逐戰，令人
看了不覺莞爾。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/poison/npc/vler1.c" : 1,
  "/open/poison/npc/sparrow.c" : 1,
]));
  set("outdoors", "/open/poison");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"pl3.c",
  "north" : __DIR__"pl5.c",
]));

  setup();
}
