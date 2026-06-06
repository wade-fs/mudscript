//by Casey
inherit ROOM;

void create ()
{
  set ("short", "谷中盆地");
  set ("long", @LONG
沉猛的吼聲遠遠的傳了過來，讓人覺得異常恐怖。地上的腳印的讓你
看的膽寒 ,雜草中不知藏著什麼生物 ,人就像處在暗處一樣，隨時有危
險的威脅，不知隨時可能會命喪這裡 。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dragon-mini" : 2,
]));
  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */

 "east" : __DIR__"d-13",
 
 ]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}

