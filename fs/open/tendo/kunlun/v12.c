// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "客棧");
	set("long", @LONG
一間和這裡完全不相襯的客棧，裡面生意可是興隆的很，一
點也不像是窮鄉僻壤該有的冷清模樣大概是這附近只有這家客棧
的關係吧....想不來都不行。這裡似乎已成了進崑崙山的招牌了
，無論是來這求仙或賞景的遊客都會到這兒落腳歇息，順便打聽
一些關於崑崙的消息。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" :__DIR__"v9",
	"up"    :__DIR__"v13",
]));
	set("objects", ([ /* sizeof() == 2 */
	__DIR__"npc/two" : 1,
	__DIR__"npc/pin" : 1,
          ]));
	set("light_up",1);
	set("outdoors",0);

	setup();
}
