// Room: /open/ping/room/m9.c ~night~(小戀)

inherit ROOM;

void create ()
{
  set ("short", "風行森林");
  set ("long", @LONG

森林中瀰漫著一絲霧氣,四周長滿了高大的樹木,使得太陽的光線不容易照進來,冷颼颼的陰
風輕輕的從你身後吹了過來,讓你感到微微的寒意,森林中有許多野獸出沒,似乎隨時都會從
森林黑暗處衝出來,讓你不得不提高警覺.你往前方望去,隱隱約約好像看到一座不算太高的
山,過去一探究竟吧。


LONG);

  set("objects", ([ /* sizeof() == 1 */
]));

  set("outdoors", "/open/ping");

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"m6",
  "north" : __DIR__"m12",
  "west"  : __DIR__"m8",
  "east"  : __DIR__"m7",
]));

  setup();
}
