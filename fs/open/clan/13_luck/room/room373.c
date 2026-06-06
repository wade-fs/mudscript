inherit ROOM;
void create() {
	set( "short", "殿前大校場四" );
	set( "object", ([
		"amount10" : 104,
		"amount9"  : 170,
		"file3"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/open/fire-hole/obj/p-pill",
		"amount5"  : 120,
		"file5"    : "/open/fire-hole/obj/b-pill",
		"file2"    : "/open/fire-hole/obj/k-pill",
		"file8"    : "/open/fire-hole/obj/g-pill",
		"amount2"  : 337,
		"amount8"  : 599,
		"amount6"  : 1554,
		"amount1"  : 59,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 219,
		"file10"   : "/open/fire-hole/obj/r-pill",
		"file9"    : "/open/fire-hole/obj/g-pill",
		"amount3"  : 1000,
		"file4"    : "/open/fire-hole/obj/y-pill",
	]) );
	set( "owner", "roar" );
	set( "build", 10260 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room372",
		"east"      : "/open/clan/13_luck/room/room387",
	]) );
	set( "long", @LONG

    這裡是校場的西側，往東則通往校場的中央。因這裡較靠近十三吉祥
四大分堂裡的『十三刀堂』及『十三拳堂』，所以兩堂弟子在此演武的人
數也較其他兩堂為多。校場的西側道路則通往『十三刀堂』。

LONG);
	setup();
	replace_program(ROOM);
}
