inherit ROOM;
void create() {
	set( "short", "元素峽谷外" );
	set( "object", ([
		"amount6"  : 1,
		"file3"    : "/open/gsword/obj1/karmband",
		"file4"    : "/open/gsword/npc2/sadsword",
		"amount3"  : 1,
		"file2"    : "/open/gsword/obj1/khelmet",
		"amount5"  : 1,
		"file1"    : "/open/gsword/obj1/bloodsword",
		"amount2"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_cape",
		"file5"    : "/open/gsword/obj1/ring",
		"amount1"  : 1,
		"amount4"  : 1,
	]) );
	set( "owner", "ywarter" );
	set( "build", 10545 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room337.c",
		"east"      : "/open/clan/sky-wu-chi/room/room339.c",
		"west"      : "/open/clan/sky-wu-chi/room/room340",
		"out"       : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
這裡你看到了黑白紅藍綠黃這六種元素,而這六種元素正密集且不消散的
在這一空間裡移動,在移動的同時你看到一些不同元素的磨擦產生的一些
微小電子,而你看到這空間的中心有一個神秘的圓球正在吸取這些微小的電子
你不知道這是什麼東西,而且這圓球還不時的擩動著,彷彿像是一個活物
LONG);
	setup();
	replace_program(ROOM);
}
