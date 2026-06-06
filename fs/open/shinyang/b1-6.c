// Room: /u/w/whatup/area/shinyang/b1-7.c
inherit ROOM;

void create ()
{
  set ("short", "牢房");
  set ("long", @LONG
一個不大的空間裡只有一張石板做的床，地上鋪稻草發出陣陣的
霉味，幾個犯人靠坐在牆邊無聲無息的，一個年邁的犯人躺在石板床
上不停的顫抖，幾個犯人拖著腳上的鐐銬，在那來回走動發出刺耳的
聲音跟陣陣的火花。
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"b1-4.c",
]));
  set("no_auc", 1);

  setup();
}
