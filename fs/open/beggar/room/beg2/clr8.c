// Room: /u/g/guetenr/beggar/room/beg2/clr8.c
inherit ROOM;

void create ()
{
  set ("short", "太君山腳");
  set ("long", @LONG
長草淹腳，樹木蒼翠，時有昆蟲獸鳴聲，向南望去只見一座古橋
，那便是歷史悠久的太湖橋，再向西南望去只見一座高聳參天的高山
佇立在眼前，隱隱約約在山頭可見一間破舊的祠堂坐落著，天色逐漸
暗淡，向山頂攀登似乎不太可能，忽見烏雲密佈，遠處傳來陣陣狼嚎
，你心下不禁慌亂，只想及早離開此地。
LONG);

  set("outdoors", "/open/beggar");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"clr7.c",
  "west" : __DIR__"clr9.c",
]));

  setup();
}
