// Room: /u/m/moner/room/room16.c
inherit ROOM;

void create ()
{
  set ("short", "內房");
  set ("long", @LONG

經過蜿埏的長廊後, 你來到了內房, 往東私乎是某人的臥房, 往東通
往書房, 往南是水雲軒。輕羅紗窗外飄著朵朵的白雲, 淡淡的翠竹葉延
伸至室內, 一種飄渺的感覺襲上你的心頭。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room17.c",
  "north" : __DIR__"room10.c",
]));
  set("light_up", 1);

  setup();
}
