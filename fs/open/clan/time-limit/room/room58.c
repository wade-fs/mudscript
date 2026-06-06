inherit ROOM;
void create() {
	set( "short", "$HIG$四年級生$HIY$教室$NOR$" );
	set( "owner", "wateribbon" );
	set( "object", ([
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount10" : 1,
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10097 );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room60",
		"east"      : "/open/clan/time-limit/room/room39.c",
		"west"      : "/open/clan/time-limit/room/room32",
		"north"     : "/open/clan/time-limit/room/room57.c",
	]) );
	set( "long", @LONG
幾位四年級生圍在一起討論前一陣子的魁地奇世界盃比賽,每個人說得
口沫橫飛,好像親自參與比賽一樣,但是一提到比賽後有人鬧事的橋段,
每個人臉上都顯現驚恐的表情,不但有人受傷,甚至還出現黑魔標記,
當時還引起一陣恐慌,以為那個人又出現了,嚇得所有人趕緊離開現場

LONG);
	setup();
	replace_program(ROOM);
}
