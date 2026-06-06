//by Casey
inherit ROOM;

void create ()
{
  set ("short", "谷中盆地");
  set ("long", @LONG
沉猛的吼聲遠遠傳了過來，讓人覺得異常恐怖。地上的腳印的讓你
看的膽寒，雜草中不知藏著什麼生物，人就像處在暗處一樣，隨時有危
險的威脅，不知何時便會命喪於此，東邊的鐘乳洞中，有個幽靜的地底
湖泊，然而湛藍色湖水發出的迫人寒氣，卻使你不敢潛入一探究竟。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dragon-mini" : 3,
]));
  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 43*/
 "south" : __DIR__"d-15",
 "west" : __DIR__"d-8",
"north" : __DIR__"d-5",

 ]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
