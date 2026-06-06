inherit ROOM;
void create() {
	set( "short", "$HIG$OMG的閨房$NOR$" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "build", 10946 );
	set( "object", ([
		"file10"   : "/daemon/class/fighter/ywhand",
		"file7"    : "/daemon/class/fighter/armband",
		"file6"    : "/open/mon/obj/mon-pill",
		"amount10" : 1,
		"file5"    : "/open/ping/questsfan/obj/box",
		"file4"    : "/open/ping/questsfan/obj/glaze",
		"amount5"  : 1,
		"amount6"  : 868,
		"amount7"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/ping/obj/cloud_fan",
		"file1"    : "/open/ping/questsfan/obj/diamond_legging",
		"file2"    : "/open/ping/questsfan/obj/manual",
	]) );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room142",
	]) );
	set( "long", @LONG
當你一走進這裡時，綠色水晶馬上發射出一道綠色的光射向了你
你急忙的四處閃躲，但是這樣是沒有用的，隨著你的閃躲的速的加快
水晶所射出來的光也就越快，並且越多道，所以只好你在不得已的情
況之下，只能落慌而逃，但是只是你不知道當你逃到別的地方時，也
正有一些同樣的防衛裝置正在等著你，並且是威力更強，所以你受死
吧。納命來，要怪只能怪你自己學藝不精。

LONG);
	setup();
	replace_program(ROOM);
}
