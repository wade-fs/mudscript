inherit ROOM;
void create() {
	set( "short", "$MAG$【縹緲空間】$NOR$" );
	set( "owner", "peiyi" );
	set( "object", ([
		"amount10" : 1,
		"file4"    : "/open/poison/obj/pearl",
		"amount2"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"file5"    : "/daemon/class/blademan/obj/shield",
		"file8"    : "/open/ping/obj/cloud_fan",
		"amount1"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 11625 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room74",
	]) );
	set( "long", @LONG
一踏進此處，頓然覺得重心全失，身體輕得似乎要飄了起來，四周
氤氳繚繞，不著邊際，這裡是小佩佩平常練跳舞的場所。這裡是一處非
常神奇的地方，重力與旁邊的地區不一樣，所以在這裡的人會覺得自己
似乎能飛了起來，也因為如此，小佩佩選擇了此處定居，在這裡練習高
級的跳舞技術，這裡還有一項神奇的功能，就是可以把法術的威力擴大
好幾倍，這讓小佩佩在冥思的時候，腦筋可以更清楚的想出一些奇特的
舞步。

LONG);
	setup();
	replace_program(ROOM);
}
