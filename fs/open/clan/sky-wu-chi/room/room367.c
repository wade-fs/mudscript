inherit ROOM;
void create() {
	set( "short", "藏經閣---" );
	set( "owner", "matrix" );
	set( "object", ([
		"amount10" : 1,
		"amount6"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"amount1"  : 1,
		"amount5"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount8"  : 1,
		"file5"    : "/open/prayer/obj/boris-boots",
		"file1"    : "/open/dancer/obj/yuawaist",
		"file7"    : "/open/prayer/obj/boris-hat",
		"file10"   : "/open/prayer/obj/boris-hands",
		"amount7"  : 1,
	]) );
	set( "build", 10167 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room366.c",
		"east"      : "/open/clan/sky-wu-chi/room/room76",
	]) );
	set( "long", @LONG
房間四璧的書架上堆滿了各門各派之武功秘笈以及未曾聽聞的絕學 
每一種無不是武者夢寐以求的武功, 牆上還有某種武功的修練圖式
吸引了你的注意, 難到........
這是傳說中的  先天乾坤功  ??? 你更仔細察看四周, 有幾樣
東西更令你心動--修練渾天心法的水晶--, 嘿嘿嘿, 你打從心裏
自然的生出想  A走它  的壞念頭, 管它什麼道義天理,   老子我
功力強, 就是天理, 哇哈哈~~~ tin force 才是王道啊!!!
LONG);
	setup();
	replace_program(ROOM);
}
