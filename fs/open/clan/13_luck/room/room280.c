inherit ROOM;
void create() {
	set( "short", "吉祥埋劍室" );
	set( "owner", "amdxp" );
	set( "object", ([
		"file1"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount7"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount2"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount4"  : 1,
		"amount1"  : 1,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room269",
	]) );
	set( "build", 10473 );
	set( "light_up", 1 );
	set( "long", @LONG

    此室放著各式各樣的劍，傳說中的連陽劍，無堅不摧的倚天劍，各
種好劍都在其中，也是吉祥的先烈們一手打來的，而連陽劍在仙劍現任
掌門鄭士欣之手，使出劍氣連陽更是暴力無窮，而倚天劍在小東邪郭襄
之手，而小東邪除了掌法，劍術也學到真傳，只能小心小心在小心的去
打，不然只是去送死而已。


LONG);
	setup();
	replace_program(ROOM);
}
