inherit ROOM;
void create() {
	set( "short", "收藏室" );
	set( "light_up", 1 );
	set( "object", ([
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount3"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 38,
		"amount8"  : 15,
		"file3"    : "/obj/gift/hobowdan",
		"file1"    : "/obj/gift/unknowdan",
		"file8"    : "/open/fire-hole/obj/b-pill",
		"amount6"  : 1,
		"file9"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
		"file5"    : "/open/gblade/obj/sa-head",
		"file10"   : "/obj/gift/xiandan",
	]) );
	set( "build", 10055 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room555",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
當你一進到房間裡面,就發現這一個房間裡面一塵不染
可以知道這裡的主人是一個很愛乾淨的人,可是在房間的地板上..有畫著一個奇怪的圖形
讓人猜不透這圖形是要做什麼的,或許你可以從附近找到一些線索.
來幫助你了解這個圖形的用處.
LONG);
	setup();
	replace_program(ROOM);
}
