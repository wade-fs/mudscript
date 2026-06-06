inherit ROOM;
void create() {
	set( "short", "$HIC$波-金屋藏嬌(5)$NOR$" );
	set( "owner", "perth" );
	set( "object", ([
		"amount10" : 1,
		"amount7"  : 1,
		"file5"    : "/open/capital/obj/king-boots",
		"amount3"  : 1,
		"file7"    : "/open/capital/obj/king-cloth",
		"file2"    : "/open/capital/obj/king-cloak",
		"file1"    : "/open/capital/obj/king-belt",
		"amount2"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/ping/obj/poison_pill",
		"file6"    : "/open/capital/obj/king-ring",
		"file4"    : "/open/capital/obj/king-ring",
		"amount9"  : 1,
		"file3"    : "/open/capital/guard/gring",
		"amount8"  : 228,
		"file10"   : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10873 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room326",
		"east"      : "/open/clan/ou-cloud-club/room/room137.c",
	]) );
	set( "long", @LONG
  嬌  金屋  金屋  嬌  金屋  金屋  嬌  金屋  
金屋  嬌  金屋  金屋  嬌  金屋  金屋  嬌  金屋  
金屋  嬌  金屋  金屋  嬌  金屋  金屋  嬌  金屋  
金屋  嬌  金屋  金屋  嬌  金屋  金屋  嬌  金屋  
金屋  嬌  金屋  金屋  嬌  金屋  金屋  嬌  金屋  
金屋  嬌  金屋  金屋  嬌  金屋  金屋  嬌  金屋  

LONG);
	setup();
	replace_program(ROOM);
}
