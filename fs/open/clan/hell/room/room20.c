inherit ROOM;
void create() {
	set( "short", "又小又軟的辦公室" );
	set( "owner", "uesz" );
	set( "object", ([
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/start/obj/ten_pen",
		"file5"    : "/open/badman/obj/badhelmet",
		"file2"    : "/daemon/class/blademan/obj/shield",
		"file6"    : "/daemon/class/fighter/ywgem",
		"amount6"  : 1,
		"file3"    : "/open/ping/obj/ring-2",
		"file4"    : "/open/clan/area/home/hae_bag",
		"amount2"  : 1,
		"file7"    : "/daemon/class/fighter/ywleg",
		"amount8"  : 1,
		"file8"    : "/daemon/class/fighter/armband",
		"amount7"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10809 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room8",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是又小又軟的辦公室，裡面只擺了一張小桌子和椅子，桌上東西亂七八糟，
看來他似乎是個很隨便的人。你四處晃晃，最後發現這裡根本不是他辦公的地方，
因為他忙得很，整天為了幫派的事情努力奮鬥，對於他來說，辦公室只是個裝飾品罷了。
一想到這裡，你不禁覺得這個偉大的人真是你應該效法的對象啊!!!

LONG);
	setup();
	replace_program(ROOM);
}
