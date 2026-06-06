inherit ROOM;
void create() {
	set( "short", "小豬頭的東廂房" );
	set( "owner", "pighead" );
	set( "object", ([
		"file7"    : "/open/mogi/dragon/obj/key",
		"file8"    : "/open/wu/npc/obj/armband",
		"amount2"  : 1,
		"amount10" : 1,
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount4"  : 9,
		"file1"    : "/open/fire-hole/obj/y-pill",
		"file2"    : "/open/gsword/obj1/blosword",
		"amount1"  : 20,
		"file6"    : "/open/killer/obj/k_ring",
		"amount8"  : 1,
		"file4"    : "/open/fire-hole/obj/b-pill",
		"file5"    : "/open/ping/obj/gold_hand",
		"amount9"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/gsword/obj1/blosword",
		"file10"   : "/open/fire-hole/obj/b-pill",
	]) );
	set( "build", 10245 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room127",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    這裡是可愛小豬頭的東廂房，這邊主要是儲存戰鬥用的防具，例
如菩薩袈裟，陽炎臂環，金織手套，等都是在戰鬥中不可缺乏的防具
，如果沒了它們，那是要如何抵抗狂想空間中的變態怪物，所以這裡
的存放的防具都是很珍貴的。

LONG);
	setup();
	replace_program(ROOM);
}
