inherit ROOM;
void create() {
	set( "short", "甘溫拿小舖" );
	set( "object", ([
		"amount5"  : 1,
		"file6"    : "/open/wind-rain/obj/bird-blade",
		"file5"    : "/open/gsword/obj1/swordball",
		"amount1"  : 150,
		"file1"    : "/open/fire-hole/obj/y-pill",
		"amount2"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"amount8"  : 31,
		"file10"   : "/open/gsword/obj1/ring",
		"amount10" : 1,
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/mon/obj/mon-pill",
		"file2"    : "/open/ping/obj/ring-2",
	]) );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room414",
	]) );
	set( "owner", "ganwunaa" );
	set( "build", 10047 );
	set( "light_up", 1 );
	set( "long", @LONG

    幾許與眾不同的細絲垂掛在空中引起你的注意,因為這些不尋常的細絲
除了發出閃閃金光之外,更隱隱泛著一股神聖的仙氣,原來這些奇異的物質
源於仙域的千年天蠶,傳說得到天蠶守護的人,將會得到不可思議的力量...

LONG);
	setup();
	replace_program(ROOM);
}
