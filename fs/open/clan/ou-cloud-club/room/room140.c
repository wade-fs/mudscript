inherit ROOM;
void create() {
	set( "short", "旎旎的家" );
	set( "owner", "neonn" );
	set( "object", ([
		"amount6"  : 541,
		"amount5"  : 100,
		"file6"    : "/open/ping/obj/poison_pill",
		"amount3"  : 180,
		"file2"    : "/open/fire-hole/obj/g-pill",
		"file4"    : "/open/ghost-hole/obj/fire-spirit",
		"file10"   : "/open/mon/obj/thousand-nectar",
		"file3"    : "/open/doctor/pill/human_pill",
		"amount8"  : 16,
		"file8"    : "/open/mogi/castle/obj/sspill",
		"file7"    : "/open/mon/obj/mon-pill",
		"amount1"  : 700,
		"amount2"  : 194,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount7"  : 35,
		"amount10" : 2,
		"amount9"  : 291,
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 1,
		"file9"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "light_up", 1 );
	set( "build", 11223 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room16",
	]) );
	set( "long", @LONG
這裡是旎旎的家,沒事請勿大聲喧嘩....................:)
TIN FORCE 是很怕別人吵的ㄛ.不過有空的話,歡迎大家來坐坐.
旎旎也是很愛乾淨的人,千萬別把EQ丟得亂七八糟ㄛ.
有事的話,歡迎大家用E-MAIL聯絡 知道我的Email 嗎 ?

LONG);
	setup();
	replace_program(ROOM);
}
