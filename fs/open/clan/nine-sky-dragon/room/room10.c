inherit ROOM;
void create() {
	set( "short", "翔龍客棧" );
	set( "object", ([
		"file8"    : "/obj/stone/powder",
		"file6"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount8"  : 32,
		"amount10" : 1,
		"amount2"  : 34,
		"file5"    : "/open/magic-manor/obj/fon-sky-sword",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 1,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 43,
		"amount1"  : 37,
		"amount5"  : 1,
		"file10"   : "/obj/gift/unknowdan",
		"file9"    : "/open/ghost-hole/obj/fire-spirit",
		"amount6"  : 6,
		"file4"    : "/open/mon/obj/mon-pill",
		"amount4"  : 13,
		"file2"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "build", 11498 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/nine-sky-dragon/room/room12",
		"down"      : "/open/clan/nine-sky-dragon/room/hall.c",
	]) );
	set( "long", @LONG

　　遠遠看來好似有一條張著血盆大口的龍朝著你直撲而來，不過在
你定神一看時才驚覺發現原來只是一個巨大的龍頭雕像。這龍上頭背
著一塊碩大的匾額，$HIC$－－$HIY$　翔　龍　客　棧　$HIC$－－$NOR$四個斗大的燙金字
體，還隱隱發亮，這裡便是有名的翔龍客棧大門。  

LONG);
	setup();
	replace_program(ROOM);
}
