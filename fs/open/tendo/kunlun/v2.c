// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", @LONG
這兒是一個民風純樸的小村莊，這條道路橫貫著全村，雖然
這裡是個偏僻的小地方，不過來往的行人還真不少。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"v1",
	"west" : __DIR__"v8",
	"east" : __DIR__"v3",
	"north": __DIR__"shop",
]));

	  set("objects", ([ /* sizeof() == 2 */
	__DIR__"npc/sell" : 1,
]));

	set("outdoors", "1");

	setup();
}
