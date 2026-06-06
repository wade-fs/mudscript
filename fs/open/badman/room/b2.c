// Room: /open/badman/room/b2
inherit ROOM;

void create ()
{
  set ("short", "惡人谷大街");
  set ("long", @LONG
平坦的大道，在盞盞燈火的照耀下，顯得格外的寧靜祥和。若
非谷口的那塊石碑，認誰都不敢相信這山村一般的街道竟會是江湖
中黑白兩道無不聞之喪膽的惡人谷之所在。
    四周越是平靜，越是讓人不得不繃緊了每一根神經，因為誰也
不知道那看不見的危險會向你吞噬而來。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/guard" : 2,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"b3",
  "east" : __DIR__"b1",
]));

  setup();
}
