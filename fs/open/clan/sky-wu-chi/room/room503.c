inherit ROOM;
void create() {
	set( "short", "$HIC$靜心小館$NOR$" );
	set( "object", ([
		"file2"    : "/obj/stone/suipian",
		"amount5"  : 2,
		"file1"    : "/obj/stone/powder",
		"file4"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount2"  : 78,
		"amount4"  : 1,
		"file3"    : "/obj/stone/jiao",
		"amount1"  : 851,
		"file5"    : "/open/ping/obj/poison_pill",
		"amount3"  : 2,
	]) );
	set( "build", 10296 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room470",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
$HIC$座落於竹林之中，一棟由竹子組合而成的小屋，微微清
風徐徐吹來，窗邊的風鈴傳來清脆的聲響，遠方不時傳來規
律的蟲鳴，在這樣的環境中靜坐冥思，暫時忘卻俗世的糾葛
，浮動的心也會因此停了下來‧‧‧$NOR$


LONG);
	setup();
	replace_program(ROOM);
}
