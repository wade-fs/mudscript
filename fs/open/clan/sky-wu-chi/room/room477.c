inherit ROOM;
void create() {
	set( "short", "- (弒羽皇天)" );
	set( "owner", "coling" );
	set( "object", ([
		"amount6"  : 1,
		"file6"    : "/obj/gift/unknowdan",
		"amount8"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"file7"    : "/open/mon/obj/thousand-nectar",
		"amount2"  : 1,
		"file2"    : "/obj/gift/unknowdan",
		"amount7"  : 2,
		"amount5"  : 1,
		"file8"    : "/obj/gift/hobowdan",
		"amount3"  : 1,
		"file4"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"file5"    : "/obj/gift/hobowdan",
	]) );
	set( "build", 13559 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room471",
	]) );
	set( "long", @LONG
溫暖的陽光照射下來，一陣金光由陣中散發，似乎是一把劍的光
芒照射著四方。楓樹的落葉飛舞在你身旁，溫暖的感覺由心中舒透至
全身骸骨身處，似乎身上暴出無限內力，這種巨大的影響，就是由那
一把傳說中的聖劍所宣洩出來的。那一把由玫緹千辛萬苦才獲得的，
                          『絢凰』
LONG);
	setup();
	replace_program(ROOM);
}
