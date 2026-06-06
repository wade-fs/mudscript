inherit ROOM;
void create() {
	set( "short", "$HIR$親密$HIM$接觸$NOR$" );
	set( "owner", "flyindance" );
	set( "object", ([
		"amount10" : 1,
		"file4"    : "/open/mon/obj/mon-pill",
		"file7"    : "/open/fire-hole/obj/k-pill",
		"amount1"  : 112,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 1,
		"amount4"  : 225,
		"amount6"  : 10,
		"amount7"  : 10,
		"amount5"  : 10,
		"file5"    : "/open/fire-hole/obj/w-pill",
		"file10"   : "/open/dancer/obj/maple_ribbon",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 78,
		"amount3"  : 93,
		"file9"    : "/daemon/class/fighter/armband",
		"file6"    : "/open/fire-hole/obj/r-pill",
		"file1"    : "/open/mogi/mountain/obj/frog-pill",
	]) );
	set( "build", 10125 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room445.c",
	]) );
	set( "long", @LONG
　　　　　　　　　　　　　
我輕輕地舞著，在擁擠的人群之中。 
你投射過來異樣的眼神。 
詫異也好，欣賞也罷。 
並不曾使我的舞步凌亂。 
因為令我飛揚的，不是你注視的目光。 
而是我年輕的心。
　　　　　　　　　　　　　輕舞飛揚
LONG);
	setup();
	replace_program(ROOM);
}
