inherit ROOM;
void create() {
	set( "short", "龍元精元房" );
	set( "object", ([
		"amount9"  : 1,
		"amount4"  : 16,
		"file6"    : "/open/fire-hole/obj/p-pill",
		"file9"    : "/open/mogi/dragon/obj/dragon-head",
		"file3"    : "/open/fire-hole/obj/y-pill",
		"amount8"  : 1,
		"amount5"  : 65,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount6"  : 136,
		"amount7"  : 81,
		"file2"    : "/open/fire-hole/obj/b-pill",
		"amount2"  : 174,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 62,
		"file7"    : "/open/fire-hole/obj/k-pill",
		"file5"    : "/open/fire-hole/obj/g-pill",
		"file8"    : "/open/mogi/dragon/obj/dragon-head",
		"amount3"  : 108,
	]) );
	set( "build", 30144 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room733.c",
		"enter"     : "/open/clan/13_luck/room/room764",
	]) );
	set( "owner", "adeyzit" );
	set( "long", @LONG
一進入這個房間，你可以發現兩旁有很多的葯物櫃，上面有一張標示，
龍元精元，看來這裡面所存放的都是龍元精元，除此之外，房間的中間還
有一個爐鼎，應該是拿來煉丹用的，該不會是要把這些精元拿來煉丹吧，
那這樣的話練出來的會是什麼藥!!!
LONG);
	setup();
	replace_program(ROOM);
}
