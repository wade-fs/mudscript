inherit ROOM;
void create() {
	set( "short", "吉祥林道" );
	set( "owner", "amdmp" );
	set( "object", ([
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/obj/lunar-heart",
		"file3"    : "/open/magic-manor/obj/lunar-heart",
		"amount8"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/magic-manor/obj/sun-heart",
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount4"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/obj/sun-heart",
		"file10"   : "/open/magic-manor/obj/sun-heart",
		"file4"    : "/open/magic-manor/obj/lunar-heart",
		"amount7"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/magic-manor/obj/lunar-heart",
	]) );
	set( "build", 10315 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room153",
		"west"      : "/open/clan/13_luck/room/room2",
	]) );
	set( "long", @LONG

　　兩旁樹木整齊緊靠的向前沿伸，形成一自然的林道，四周一片綠
意盎然，一陣微風吹拂而過，樹葉隨風搖曳，猶如一片樹海似的。微
風挾帶著秋天的氣息，徐徐吹來令人覺的神輕氣爽。陽光透過枝葉灑
下點點金黃，美不勝收。

LONG);
	setup();
	replace_program(ROOM);
}
