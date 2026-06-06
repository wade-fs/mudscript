// Room : /open/clan/ou-cloud-club/room/room126.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
通往傲雲山莊內的道路，左右路旁插滿著各　　
門各派的敬賀標語，還有受聘於傲雲山莊的武師　　
們，莊前大道何其威武，殊不知傲雲山莊乃武林　　
中第一大幫，普通人等豈可輕鬆進入莊內，故莊　　
前有著非常嚴厲的關卡把守著．　　

LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "clan_room", "傲雲山莊" );
	set( "light_up", 1 );
	set( "short", "山莊大道" );
	set( "object", ([
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/obj/water-ball",
		"file9"    : "/open/magic-manor/obj/fire-ball",
		"amount8"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/obj/wood-ball",
		"amount6"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/obj/golden-ball",
		"file6"    : "/open/magic-manor/obj/water-ball",
		"file2"    : "/open/magic-manor/obj/wood-ball",
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/obj/golden-ball",
		"amount2"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/obj/wood-ball",
		"file1"    : "/open/magic-manor/obj/golden-ball",
		"file7"    : "/open/magic-manor/obj/wood-ball",
		"amount4"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 16538 );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"out"       : "/open/clan/ou-cloud-club/room/room124.c",
		"north"     : "/open/clan/ou-cloud-club/room/hall",
]) );
	setup();

	}
