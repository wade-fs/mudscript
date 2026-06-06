// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", @LONG
這兒是一個民風純樸的小村莊，這條道路橫貫著全村，雖然
這裡是個偏僻的小地方，不過來往的行人還真不少。南邊有家滿
大的客棧。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"v12",
	"east" : __DIR__"v8",
	"north" : __DIR__"v10",
]));

	  set("objects", ([ /* sizeof() == 2 */
	__DIR__"npc/visitor" : 2,
]));

	set("outdoors", "1");

	setup();
}
