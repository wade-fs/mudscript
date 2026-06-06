inherit ROOM;
void create() {
	set( "short", "$HIG$妖刀界$NOR$-$HIR$封神林$NOR$" );
	set( "owner", "dking" );
	set( "object", ([
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"amount10" : 1,
		"amount5"  : 1,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"amount8"  : 1,
	]) );
	set( "build", 10089 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room584.c",
		"south"     : "/open/clan/ou-cloud-club/room/room586",
		"east"      : "/open/clan/ou-cloud-club/room/room588.c",
		"north"     : "/open/clan/ou-cloud-club/room/room587",
		"down"      : "/open/clan/ou-cloud-club/room/room250.c",
	]) );
	set( "long", @LONG
通過上帝禁區之後，終於來到妖刀界，此地名為封神林，是三百年前
刀魔  星野殘紅與一百零八位天界高手激戰之後，將之元神封印起來
的封印地，來到這裡，你要小心了，若你身上流有天界之血，那顧守
此地的兩隻魔獸，將會把你擊殺，並將你的元神封印，讓你長眠於此
。

太古魔龍  應龍 (Old-dragon)

萬年火鳳  妖凰 (Old-bird)
LONG);
	setup();
	replace_program(ROOM);
}
