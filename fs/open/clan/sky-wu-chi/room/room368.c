inherit ROOM;
void create() {
	set( "short", "$HIC$思量之家$HIW$一般EQ室$NOR$" );
	set( "owner", "salicili" );
	set( "object", ([
		"file7"    : "/open/killer/headkill/obj/world_dag",
		"amount8"  : 27,
		"amount6"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"file2"    : "/daemon/class/bonze/puty_pullium",
		"file1"    : "/open/poison/obj/feather",
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"file8"    : "/open/mogi/castle/obj/sspill",
		"file9"    : "/daemon/class/fighter/figring",
		"file3"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "build", 10827 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room128",
		"east"      : "/open/clan/sky-wu-chi/room/room24",
	]) );
	set( "long", @LONG
這裡是思量偷偷造的小房間,
為了偷懶,不要去殺mob搶EQ,
公款又有一部分消失在這裡,
雖然說這是一間儲藏室,
但是,..................
你發現一件詭異的事,
那就是
這裡空空的,你什麼都沒看到~~~~
看不到  看不到  看不到 ^_^
LONG);
	setup();
	replace_program(ROOM);
}
