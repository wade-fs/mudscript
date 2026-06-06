// Room: /open/main/room/cloister.c


inherit ROOM;

void create()
{
	set("valid_startroom",1);
	set("short","崑崙道觀");
	set("light_up",1);
	set("long", @LONG
一間座落崑崙已久的舊道觀，看起來不怎麼
富麗堂皇，不過倒是窗明几淨，是個適合修生養
性的好地方。

LONG
	);
	set("objects",([
	"/daemon/class/taoist/master" : 1,
		]) );
	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"v4",
]));

	setup();

}
