// Room: /open/badman/room/b7
inherit ROOM;

void create ()
{
  set ("short", "殿前大道");
  set ("long", @LONG
你終於來到殿前大道的盡頭，南北兩邊的街道上行人稀稀落落
，似乎充滿著肅殺之氣。你看到西邊有一棟雄偉的建築，大門上掛
著一塊寫著『惡人谷』的匾額，門口還燃著兩盆熊熊的火炬。在火
焰的照耀下，顯得特別神秘，令人透不過氣來。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"b19",
  "north" : __DIR__"b13",
  "west" : __DIR__"g1",
  "east" : __DIR__"b6",
]));
  set("outdoors", "/open/badman");

  setup();
}
