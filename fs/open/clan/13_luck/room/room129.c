inherit ROOM;
void create() {
	set( "short", "狂人專用停車場" );
	set( "owner", "mill" );
	set( "object", ([
		"amount2"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount4"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount3"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount8"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armor",
	]) );
	set( "build", 10046 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room594.c",
		"enter"     : "/open/clan/13_luck/room/room131.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    走進這裡，發現到居然有各式各樣的跑車，名車，認真一看都是F1賽
車和一些世面上每個人搶著要的名車，這個幫派的幫主還真是愛車族的一
員啊。往左邊一看又發現到連卡通的ㄚ斯拉跑車也有ㄛ，往裡面一坐，還
真的會檢查使用者的眼角膜跟音頻，這個幫主來頭一定不小。


LONG);
	setup();
	replace_program(ROOM);
}
