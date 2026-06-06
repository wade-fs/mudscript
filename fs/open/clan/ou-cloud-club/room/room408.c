inherit ROOM;
void create() {
	set( "short", "頓悟之間" );
	set( "owner", "alus" );
	set( "object", ([
		"amount3"  : 2610,
		"amount2"  : 1,
		"file7"    : "/obj/gift/bingtang",
		"amount8"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/obj/master_snake_head",
		"amount1"  : 1,
		"file8"    : "/obj/gift/lingzhi",
		"file2"    : "/obj/gift/lingzhi",
		"amount4"  : 2719,
		"file1"    : "/open/killer/headkill/obj/sword_head",
		"amount5"  : 195,
		"file6"    : "/obj/gift/xisuidan",
		"amount9"  : 1,
		"file5"    : "/open/killer/obj/atman_pill",
		"file4"    : "/obj/poison/five_poison",
		"amount10" : 1,
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"file3"    : "/obj/poison/faint_poison",
	]) );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room413",
	]) );
	set( "build", 10337 );
	set( "light_up", 1 );
	set( "long", @LONG
走進空蕩蕩的房間裡，舉目望去，只有看到一盞昏暗的燭火靜靜地
點亮在牆角邊，地上擺著一塊打坐用的蒲團。緊閉的門窗讓屋內充滿著
一股沉靜的氣息。這裡是趴趴熊平日冥思和靜坐的地方。也歡迎想換換
心情的人入內參觀，不過請保持安靜，別打擾在此的修煉的人。
LONG);
	setup();
	replace_program(ROOM);
}
