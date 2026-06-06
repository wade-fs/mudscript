// Room: /u/g/guetenr/beggar/room/beg2/clr10.c
inherit ROOM;

void create ()
{
  set ("short", "太君山腳");
  set ("long", @LONG
長草淹腳，樹木蒼翠，時有昆蟲獸鳴聲，向西望去只見一片綠
意鬱鬱的森林，遍佈荊棘，向西南望去只見一座高山，那便是雄偉
壯闊的太君山，隱隱約約在山頭可見一間破舊的祠堂坐落著，天色
逐漸暗淡，向山頂攀登似乎不太可能，忽見烏雲密佈，遠處傳來陣
陣狼嚎，你心下不禁慌亂，只想及早離開此地。
LONG);

  set("outdoors", "/open/beggar");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"clr11.c",
  "northdown" : __DIR__"clr9.c",
]));

  setup();
}
