inherit ROOM;
void create() {
	set( "short", "沁芳亭" );
	set( "owner", "jsa" );
	set( "object", ([
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"amount5"  : 1,
		"file5"    : "/open/gsword/obj/dragon-sword",
		"file1"    : "/open/gsword/obj/silver_sword",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount9"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/gsword/obj1/blosword",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"file2"    : "/open/main/obj/firesword",
	]) );
	set( "build", 10140 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room200.c",
		"north"     : "/open/clan/sky-wu-chi/room/room216",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
面對一池蓮花的八角亭子，琉璃瓦的飛簷依天光雲
影變幻著色澤，八柱子下設有矮欄以供坐落，相櫬之下
顯得熱鬧又不落俗套；亭中置圓形石桌與圓椅，皆覆以
四方布以隔石寒氣，待仲夏夜中水殿風來，於此小坐片
刻，不覺暑氣全消心曠神怡。
LONG);
	setup();
	replace_program(ROOM);
}
