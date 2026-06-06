// Room: /open/main/room/s21.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
	set( "build", 48 );
  set ("long", @LONG
	這裡是御林軍專用的操練場，由於乃軍機重地，
	故守衛十分的森嚴，周圍用柵欄圍了起來，入口
	前有塊告示碑(marker)。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "marker" : "			軍機重地

		      非洽公要務，
		立    入    者    斬！

			三品御前帶刀御林軍軍長  霍拔

",
]));

  set("objects", ([ /* sizeof() == 2 */
  "/open/center/npc/brownhorse" : 1,
  "/open/center/npc/blackhorse" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"s17",
  "west" : __DIR__"s20",
  "east" : __DIR__"s22",
]));

  setup();
}
