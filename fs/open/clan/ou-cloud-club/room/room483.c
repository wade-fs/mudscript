inherit ROOM;
void create() {
	set( "short", "Hockenheimring" );
	set( "object", ([
		"file8"    : "/obj/gift/lingzhi",
		"amount2"  : 1,
		"file9"    : "/obj/gift/lingzhi",
		"file2"    : "/obj/gift/lingzhi",
		"file4"    : "/obj/gift/lingzhi",
		"amount5"  : 1,
		"file3"    : "/obj/gift/bingtang",
		"amount3"  : 1,
		"amount9"  : 1,
		"file1"    : "/obj/gift/lingzhi",
		"file5"    : "/obj/gift/bingtang",
		"amount8"  : 1,
		"amount6"  : 1,
		"file10"   : "/obj/gift/lingzhi",
		"amount7"  : 1,
		"file6"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"file7"    : "/obj/gift/bingtang",
		"amount4"  : 1,
		"amount10" : 1,
	]) );
	set( "build", 18501 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room486",
	]) );
	set( "long", @LONG
德國賀根海姆賽道,也是一個典型的高速賽道,因為直線跑道
距離長,所以在這裡用到5到6速是家常便飯的事,不過這裡的擁有
者並不是因為看上這個跑道才仿照賀根海姆賽道再這裡建造的 ,
因為那附近的景觀相當棒,尤其是車道附近會有一片的森林圍住,
給人的感覺相當好,這賽道的彎道有,Nord彎道,Einfarhrt拋物彎
Hochgeschwindigkeits拋物彎,Spitzkehre彎道,Mobil 1彎道,Sa
chs彎道,SUd彎道。

LONG);
	setup();
	replace_program(ROOM);
}
