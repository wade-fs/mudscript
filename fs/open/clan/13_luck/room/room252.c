inherit ROOM;
void create() {
	set( "short", "『山腳』" );
	set( "owner", "poll" );
	set( "object", ([
		"file2"    : "/open/killer/outsea/dstone",
		"file3"    : "/open/killer/outsea/dstone",
		"file8"    : "/open/gsword/obj/yuboots",
		"amount8"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"amount9"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount3"  : 1,
		"file4"    : "/open/killer/outsea/dstone",
		"amount4"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10056 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room250",
		"north"     : "/open/clan/13_luck/room/room249",
	]) );
	set( "long", @LONG
愈往北邊的山路爬上來，愈覺得空氣新鮮，不像江湖上濃厚的殺氣一般
。愈往山底下的景色看過去，看到剛剛遇到的那個城鎮，旁邊的小河也似乎
都化成咆哮的滾流，湍急得水面在陽光下閃爍著繽紛的色彩。而平常的落日
嫣霞都映照成一片美麗的景象，讓你個眼睛看著目不暇給。
LONG);
	setup();
	replace_program(ROOM);
}
