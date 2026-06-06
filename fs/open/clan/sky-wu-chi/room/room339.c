inherit ROOM;
void create() {
	set( "short", "元素峽谷右" );
	set( "object", ([
		"file4"    : "/open/gsword/npc2/sadsword",
		"file3"    : "/open/gsword/obj1/khelmet",
		"amount6"  : 1,
		"file7"    : "/open/firedancer/npc/eq/r_cloth",
		"amount10" : 1,
		"amount7"  : 1,
		"file1"    : "/open/main/obj/bird_legging",
		"file10"   : "/open/firedancer/npc/eq/r_shield",
		"file6"    : "/open/gsword/obj1/ring",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/main/obj/m_cloak",
		"amount2"  : 1,
		"file8"    : "/open/firedancer/npc/eq/r_head",
		"amount9"  : 1,
		"file5"    : "/open/gsword/obj1/karmband",
		"amount4"  : 1,
		"file9"    : "/open/firedancer/npc/eq/r_belt",
	]) );
	set( "owner", "ywarter" );
	set( "build", 10050 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room338",
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
