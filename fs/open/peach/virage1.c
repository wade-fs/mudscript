// Room: /u/w/whatup/peach/virage1
inherit ROOM;

void create ()
{
  set ("short", "桃花源村外");
  set ("long", @LONG
經過一大片農田，讓你確認前方是個農村，終於可以填飽肚子了
，這一片農田好像經過規劃一樣，一條條道路將農田劃成棋盤般整齊
，一名老農夫本帶著孫子坐在牛車上有說有笑，卻是突然一臉訝異的
看著你。
LONG);

  set("outdoors", "/u/b");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"virage2",
  "south" : __DIR__"hole9",
]));

  setup();
}
