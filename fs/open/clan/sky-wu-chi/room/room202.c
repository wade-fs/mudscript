inherit ROOM;
void create() {
	set( "short", "煉丹房" );
	set( "owner", "yuki" );
	set( "object", ([
		"amount3"  : 1,
		"file8"    : "/open/mon/obj/mon-pill",
		"amount1"  : 1,
		"amount9"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"amount7"  : 1,
		"file6"    : "/open/killer/obj/s_pill",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 96,
		"amount8"  : 20,
		"file1"    : "/obj/gift/unknowdan",
		"amount4"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/gsword/obj/dragon-sword",
		"file2"    : "/obj/gift/shenliwan",
		"amount10" : 1,
		"file3"    : "/open/wind-rain/obj/bird-blade",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"file10"   : "/open/gblade/obj/sa-head",
	]) );
	set( "build", 10087 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room162",
	]) );
	set( "long", @LONG
這裡是小二的煉丹房
所有FS裡面的稀有丹藥
不管是龍丹還是補滿血的丹藥
或是超貴的super pill
這裡都有...此時你居然看到
偶發事件的丹藥
神力丹,仙丹...等
這...小二真的是太神通廣大了
不過...你不是小二拿不出來
想吃....去問問小二吧...
LONG);
	setup();
	replace_program(ROOM);
}
