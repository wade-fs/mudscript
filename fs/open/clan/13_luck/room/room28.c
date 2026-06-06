inherit ROOM;
void create() {
	set( "short", "吉祥水道" );
	set( "owner", "amdxp" );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 6,
		"file9"    : "/obj/stone/powder",
		"amount5"  : 68,
		"file8"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/obj/stone/suipian",
		"amount1"  : 5,
		"amount8"  : 77,
		"file2"    : "/open/fire-hole/obj/w-pill",
		"file6"    : "/open/mon/obj/mon-pill",
		"amount6"  : 20,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"file5"    : "/open/fire-hole/obj/k-pill",
		"amount2"  : 161,
		"amount7"  : 14,
		"file1"    : "/obj/stone/jiao",
		"file4"    : "/open/capital/obj/blade2",
		"amount3"  : 345,
	]) );
	set( "build", 10782 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room29",
		"north"     : "/open/clan/13_luck/room/room27.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    吉祥水道是十三吉祥的最重要交通與運輸中心，想到十三吉祥的內
部一定要經過這裡﹐吉祥水道到處都可以看到來往的船隻，而船上的人
們都悠哉的享受水上之旅，走在路上有時還可以看到有人悠閒著釣魚，
真是愜意，在往前走就會走進秋陽流樹林。

LONG);
	setup();
	replace_program(ROOM);
}
