// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "崑崙山腳");
	set("long", @LONG
這兒是通往崑崙山的必經之路, 小小的石子路上不時可以看
到有人打從這兒走過。依照這些人裝束來看，可能都是從遠方風
塵僕僕地趕來這兒求取仙術的。路旁的風景秀麗，東山西河，不
時還有小孩在河邊玩水，想想這兒應該離村莊不遠了。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" :__DIR__"v2",
"south" : "/open/tendo/m4",
]));
	set("outdoors", "1");

	setup();
}
