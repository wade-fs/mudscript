// Room: /open/badman/room/b3
inherit ROOM;

void create ()
{
  set ("short", "惡人谷大街");
  set ("long", @LONG
道路逐漸開闊，兩旁的房子也漸漸多了起來，這惡人谷雖然是
與世隔絕，但看來谷中還是應有盡有，與外面的世界看起來沒什麼
差別。唯一令你感到不同的地方，或許是那種無時無刻不存在的壓
迫感吧。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"b4",
  "east" : __DIR__"b2",
]));
  set("outdoors", "/open/badman");

  setup();
}
