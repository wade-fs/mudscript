inherit ROOM;
void create() {
	set( "short", "ζ小南家前廳ζ" );
	set( "object", ([
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/obj/wood-ball",
		"amount3"  : 1,
		"file5"    : "/open/capital/obj/4-4",
		"amount5"  : 1,
		"file4"    : "/open/magic-manor/obj/wood-ball",
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/obj/soil-ball",
	]) );
	set( "build", 10270 );
	set( "owner", "son" );
	set( "exits", ([
		"east"      : "/open/clan/demon_castle/room/room14.c",
		"out"       : "/open/clan/demon_castle/room/room7.c",
		"north"     : "/open/clan/demon_castle/room/room4",
		"west"      : "/open/clan/demon_castle/room/room16.c",
	]) );
	set( "long", @LONG

　　歡迎您來到小南的第四度空間次元，一起分享小南的豐功偉業
此空間中充滿了銀水藍色的微小粒子，是由天地人三度空間中匯集
到金木水火土五行中的真氣，吸入小南丹田內融合了六種浩然正氣
所產生的粒子，而產生的異次元。


妳發覺藍色的迷霧圍繞正在妳四周

LONG);
	setup();
	replace_program(ROOM);
}
