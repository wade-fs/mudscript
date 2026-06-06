inherit ROOM;
void create() {
	set( "short", "夜ソ女湯" );
	set( "owner", "nafia" );
	set( "object", ([
		"amount2"  : 123,
		"amount6"  : 264,
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"file7"    : "/open/ping/obj/poison_pill",
		"amount9"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/fire-hole/obj/r-pill",
		"amount5"  : 1,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/open/mon/obj/mon-pill",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 890,
		"file2"    : "/open/fire-hole/obj/p-pill",
		"amount8"  : 1,
		"amount3"  : 120,
		"file6"    : "/open/fire-hole/obj/b-pill",
		"amount4"  : 81,
		"amount7"  : 170,
	]) );
	set( "build", 10163 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room739",
		"west"      : "/open/clan/ou-cloud-club/room/room738",
		"north"     : "/open/clan/ou-cloud-club/room/room737",
		"east"      : "/open/clan/ou-cloud-club/room/room473.c",
	]) );
	set( "long", @LONG
 $HIG$
              ◣◢◣
             █ ██◣
       ◢█◣◥██◤◢█▌
        ◥██◣◥◢██◤
         ◢██◢◣ ◥ █◣
        ◥█◤/█◥█◣◥◤
             / ████
            /  ◥ ◥◤
            ▏
            ▏
            \
             ＼$HIW$
            ▇▇▇▇▇$NOR$
                                
LONG);
	setup();
	replace_program(ROOM);
}
