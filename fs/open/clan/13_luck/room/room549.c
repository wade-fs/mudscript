inherit ROOM;
void create() {
	set( "short", "三件事很重要" );
	set( "owner", "dfyw" );
	set( "object", ([
		"amount7"  : 153,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/fire-hole/obj/w-pill",
		"file8"    : "/open/gsword/obj1/blosword",
		"amount9"  : 3,
		"file10"   : "/open/mon/obj/mon-pill",
		"file2"    : "/open/fire-hole/obj/r-pill",
		"amount10" : 7,
		"amount2"  : 49,
		"amount5"  : 105,
		"file4"    : "/open/ghost-hole/obj/light-spirit",
		"file3"    : "/open/capital/obj/blade2",
		"amount1"  : 44,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/killer/obj/atman_pill",
		"file6"    : "/u/p/pana/obj/badstaff",
		"amount4"  : 1,
		"file9"    : "/open/fire-hole/obj/r-pill",
	]) );
	set( "build", 10092 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room102",
		"enter"     : "/open/clan/13_luck/room/room548",
	]) );
	set( "long", @LONG
兩個不同生長環境的人要在一起，已經是很困難的事了，而彼此能相互
溝通、尊重與珍惜的人更是少之又少。因為許多人往往都是自私地站在
自己的立場去想、去做，以為這就是對方所需要的，以致常常意氣用事
，痛了自己也苦了別人。
所以愛一個人不是給她你要的， 因為你要的她不一定要啊 !
而是要給她「她要的」，這樣才是真正愛她。
所以，兩個人在一起有三件事很重要： 溝通‧尊重‧珍惜。
LONG);
	setup();
	replace_program(ROOM);
}
