// Room: /open/badman/room/b5
inherit ROOM;

void create ()
{
  set ("short", "殿前大道");
  set ("long", @LONG
你來到了惡人谷的殿前大道，聚集的人也漸漸多了起來，你不
時可以看到北邊的房間有人進進出出，個個獐頭鼠目，看來都不是
什麼好東西，不愧是強盜窩的中心。
    你聽到南邊傳來陣陣的吆喝聲，十分嚇人。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"b6",
  "south" : __DIR__"r6",
  "north" : __DIR__"r7",
  "east" : __DIR__"b4",
]));
  set("outdoors", "/open/badman");

  setup();
}
