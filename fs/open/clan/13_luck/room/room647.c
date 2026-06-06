inherit ROOM;
void create() {
	set( "short", "驚雲閣大門" );
	set( "object", ([
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount7"  : 91,
		"amount1"  : 571,
		"amount2"  : 137,
		"file8"    : "/open/mon/obj/thousand-nectar",
		"file7"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file5"    : "/open/fire-hole/obj/k-pill",
		"amount8"  : 95,
		"file2"    : "/open/fire-hole/obj/b-pill",
		"file4"    : "/open/fire-hole/obj/g-pill",
		"file9"    : "/open/fire-hole/obj/w-pill",
		"amount4"  : 475,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount5"  : 91,
		"amount9"  : 603,
		"file3"    : "/open/fire-hole/obj/p-pill",
		"amount3"  : 202,
		"amount6"  : 107,
	]) );
	set( "build", 10105 );
	set( "light_up", 1 );
	set( "owner", "soul" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room594",
		"enter"     : "/open/clan/13_luck/room/room646",
	]) );
	set( "long", @LONG
           　　　　　　　　　　　　　　　　　　　　   
 ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮
 ║╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯║
 ║                                        ║
 ║             『驚  雲  閣』             ║
 ║                                        ║
 ║                                        ║
 ║     ★ 『 歡  迎  光  臨  』  ★       ║
 ║                                        ║
 ║♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀♀║
 ║ ║ ║ ║ ║ ║ ║ ║ ║ ║ ║ ║ ║ ║ ║
 ║ ║ ║ ║ ║ ║ ║ ║ ║ ║ ║ ║ ║ ║ ║

LONG);
	setup();
	replace_program(ROOM);
}
