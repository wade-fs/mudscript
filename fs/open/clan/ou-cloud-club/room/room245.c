inherit ROOM;
void create() {
	set( "short", "山莊大道" );
	set( "object", ([
		"file10"   : "/open/magic-manor/obj/golden-ball",
		"amount7"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/obj/fire-ball",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/magic-manor/obj/wood-ball",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/obj/wood-ball",
		"file7"    : "/open/magic-manor/obj/soil-ball",
		"file5"    : "/open/magic-manor/obj/golden-ball",
		"amount9"  : 1,
		"file3"    : "/open/magic-manor/obj/golden-ball",
		"file9"    : "/open/magic-manor/obj/soil-ball",
		"file8"    : "/open/magic-manor/obj/golden-ball",
		"file1"    : "/open/magic-manor/obj/wood-ball",
	]) );
	set( "build", 10033 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room124.c",
	]) );
	set( "long", @LONG
通往傲雲山莊內的道路，左右路旁插滿著各　　
門各派的敬賀標語，還有受聘於傲雲山莊的武師　　
們，莊前大道何其威武，殊不知傲雲山莊乃武林　　
中第一大幫，普通人等豈可輕鬆進入莊內，故莊　　
前有著非常嚴厲的關卡把守著．

LONG);
	setup();
	replace_program(ROOM);
}
