inherit ROOM;
void create() {
	set( "short", "EMC 靶場" );
	set( "owner", "adeyzit" );
	set( "object", ([
		"amount6"  : 240,
		"amount1"  : 90,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file9"    : "/open/fire-hole/obj/w-pill",
		"amount3"  : 2,
		"amount5"  : 25,
		"file2"    : "/open/ping/obj/poison_pill",
		"amount10" : 1,
		"amount9"  : 89,
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/open/doctor/pill/gnd_pill",
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount2"  : 49,
		"file10"   : "/open/magic-manor/obj/magic-sign",
	]) );
	set( "build", 10038 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room104",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
到了靶場..心中總有一種心奮..M16 步槍.打75M 175M 300M三種..
又分臥射,跪射,立射..除了步槍..還有45 手槍..M249 機槍
跟T74 機槍..還有那 六六火箭筒,跟那60 迫炮..只差那40榴彈槍
不然步兵連武器都快到齊了..
而普通步兵連七大裝備跟四大業務..
參一二三四外加政戰,行政.. 輪車,通訊,化學,觀測,工兵,兵工,經理
LONG);
	setup();
	replace_program(ROOM);
}
