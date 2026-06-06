inherit ROOM;
void create() {
	set( "short", "相思亭" );
	set( "owner", "imissyou" );
	set( "object", ([
		"file2"    : "/open/mon/obj/mon-pill",
		"amount7"  : 1,
		"file6"    : "/open/killer/obj/kill_yar_head",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/fire-hole/obj/y-pill",
		"file8"    : "/obj/gift/bingtang",
		"amount2"  : 104,
		"file7"    : "/open/fire-hole/obj/b-pill",
		"amount3"  : 2363,
		"amount6"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/killer/obj/atman_pill",
		"file4"    : "/open/mon/obj/thousand-nectar",
		"amount1"  : 31,
		"amount9"  : 1,
	]) );
	set( "build", 10012 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room437",
	]) );
	set( "long", @LONG
岳飛【滿江紅】 
怒髮沖冠,憑闌處,瀟瀟雨歇.抬望眼,仰天長嘯,壯懷激烈.
三十功名塵與土,八千里路云和月.莫等閑,白了少年頭,空
悲切.靖康恥,猶未雪;臣子恨,何時滅.駕長車踏破,賀蘭山
缺.壯志飢餐胡虜肉,笑談渴飲匈奴血.待從頭,收拾舊山河
,朝天闕.



LONG);
	setup();
	replace_program(ROOM);
}
