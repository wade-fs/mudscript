inherit ROOM;
void create() {
	set( "short", "$HIR$禁忌$HIG$森林3$NOR$" );
	set( "owner", "goldblade" );
	set( "object", ([
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"amount10" : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
	]) );
	set( "build", 10304 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room67",
	]) );
	set( "long", @LONG
你慢慢走進人馬的區域裡,人馬是半人半馬的生物,相當的聰明,尤其
精通觀星術,人馬經常望著天空的星星一整晚以推論未來,瞧!前方
就有一個人馬正在看著天空,不過由於人馬相當驕傲,對於其他生物的態度
並非很友善,你禮貌性的向他問聲好,他只是看了你一眼,就繼續望著天空

LONG);
	setup();
	replace_program(ROOM);
}
