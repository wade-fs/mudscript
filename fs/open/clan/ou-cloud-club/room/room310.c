inherit ROOM;
void create() {
	set( "short", "$HIW$無限城$NOR$--$HIC$西方之盾$NOR$" );
	set( "owner", "del" );
	set( "object", ([
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount6"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room314",
	]) );
	set( "build", 10132 );
	set( "light_up", 1 );
	set( "long", @LONG
為主城外兵力最為強大的地方，腹地內除了廣闊的平原
外，更有暗藏於地底交錯縱橫的隧道，平時可訓練兵馬，遇
到緊急狀況時寬敞的隧道可提供主城居民作為避難的場所，
而外圍的茂密的樹林內則有數百座的雷火石台可供魔導士施
放防禦魔法，大大提高了腹地內的安全性。

LONG);
	setup();
	replace_program(ROOM);
}
