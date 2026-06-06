// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "民房");
	set("long", @LONG
一間稀鬆平常的小屋子，裡面擺了幾張竹製
的桌椅和床.......

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"v3",
]));
	set("objects", ([ /* sizeof() == 2 */
          __DIR__"npc/man" : 1,
          ]));
	set("outdoors",0);

	setup();
}
