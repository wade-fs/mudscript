inherit ROOM;
void create() {
	set( "short", "秘集室" );
	set( "object", ([
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/obj/sun-heart",
		"amount6"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/magic-manor/obj/sun-heart",
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "owner", "roar" );
	set( "build", 10287 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room186",
	]) );
	set( "long", @LONG
你來到這，發現這裡有一堆書架，你不由主的向書架前去，發現書架上的
秘集都是絕世秘集，有”天外逍遙”、”七大限”、”天晶劍絕”、”心絕神
劍”、”噬魂棍法”、”上天下地自尊功”、”一滅二霸四絕”，心想這都不
是狂想的秘技，好奇之於你一本一本的翻開看，卻發現～別人的東西不要亂翻
～這九個字。

LONG);
	setup();
	replace_program(ROOM);
}
