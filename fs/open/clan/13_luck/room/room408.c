inherit ROOM;
void create() {
	set( "short", "小豬頭的電影院" );
	set( "object", ([
		"file4"    : "/open/scholar/obj/icefan",
		"file6"    : "/open/fire-hole/obj/k-pill",
		"amount1"  : 40,
		"amount7"  : 14,
		"amount3"  : 1,
		"amount4"  : 1,
		"amount6"  : 73,
		"amount8"  : 10,
		"amount2"  : 40,
		"amount5"  : 32,
		"file8"    : "/open/fire-hole/obj/w-pill",
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file1"    : "/open/fire-hole/obj/g-pill",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"file7"    : "/open/fire-hole/obj/y-pill",
		"file3"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "owner", "pighead" );
	set( "build", 12990 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room412",
	]) );
	set( "long", @LONG

    這裡是可愛小豬頭的電影院，小豬頭在睡前總是喜歡看幾片好看
的電影，當然其中也包括小豬頭最喜歡的動作片，從片中可以得到許
多的收穫，例如新的姿勢和工具，可以讓小豬頭在實戰經驗上應用，
提高小豬頭的戰鬥力。

LONG);
	setup();
	replace_program(ROOM);
}
