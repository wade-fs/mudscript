inherit ROOM;
void create() {
	set( "short", "福林酒樓二樓" );
	set( "object", ([
		"amount6"  : 1,
		"file10"   : "/open/magic-manor/obj/lunar-heart",
		"amount3"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/obj/sun-heart",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/lunar-heart",
		"amount2"  : 1,
		"amount10" : 1,
		"file9"    : "/open/magic-manor/obj/lunar-heart",
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/obj/sun-heart",
		"file2"    : "/open/magic-manor/obj/sun-heart",
		"file7"    : "/open/magic-manor/obj/sun-heart",
		"file1"    : "/open/magic-manor/obj/lunar-heart",
		"amount1"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/obj/sun-heart",
		"file4"    : "/open/magic-manor/obj/lunar-heart",
		"amount7"  : 1,
	]) );
	set( "owner", "zmud" );
	set( "build", 10001 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room475",
	]) );
	set( "long", @LONG

    這裡是福林酒樓的二樓雅座，這裡的客人大多衣冠鮮明，若不是富
豪巨紳，便是秀才舉人，使你不知不覺跟著斯文起來，從這裡可以眺望
邑陽城的市景，東邊是碧波蕩漾的華陽湖，湖邊楊柳垂青風景十分宜人
。居高遠眺，可看到城外東方的大樹林，聽說經過樹林便可到達東武林
。你可以沿角落的方梯回到一樓，而三樓就是囍宴廳了。

LONG);
	setup();
	replace_program(ROOM);
}
