inherit ROOM;
void create() {
	set( "short", "小豬頭的南廂房" );
	set( "owner", "pighead" );
	set( "object", ([
		"file5"    : "/open/fire-hole/obj/b-pill",
		"amount5"  : 10,
		"amount8"  : 1,
		"file1"    : "/open/fire-hole/obj/g-pill",
		"file2"    : "/obj/gift/xiandan",
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount2"  : 1,
		"amount6"  : 5,
		"amount10" : 1,
		"amount1"  : 21,
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 5,
		"file8"    : "/open/gblade/obj/sa-head",
		"file6"    : "/open/fire-hole/obj/y-pill",
		"amount4"  : 1,
		"file10"   : "/open/dancer/obj/yuawaist",
	]) );
	set( "build", 10152 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room127",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡是可愛小豬頭的東廂房，這邊主要是各式各樣的道具，例如
得來不易的仙丹，魔龍鱗，千墳之水等都是在戰鬥中不可缺乏的道具
，如果沒了它們，那是要如何抵抗狂想空間中的變態怪物，所以這裡
的存放的道具都是很珍貴的。

LONG);
	setup();
	replace_program(ROOM);
}
