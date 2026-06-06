inherit ROOM;
void create() {
	set( "short", "$HIG$友情$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount10" : 1,
		"file8"    : "/open/mogi/castle/obj/lochagem",
		"amount7"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount5"  : 1,
		"file4"    : "/open/scholar/obj/icefan",
		"amount6"  : 1,
		"amount9"  : 1,
		"file9"    : "/daemon/class/fighter/ywboots",
		"amount8"  : 1,
		"file2"    : "/open/ping/obj/gold_hand",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/ping/obj/ring-2",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
	]) );
	set( "outdoors", "/open/clan/ou-cloud-club" );
	set( "owner", "bleak" );
	set( "light_up", 1 );
	set( "build", 10037 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room445",
		"east"      : "/open/clan/ou-cloud-club/room/room304.c",
	]) );
	set( "long", @LONG
世上唯一無刺的玫瑰，就是友情。
有朋友的人死得早。沒有朋友的人，活著豈非和死了差不多。
一個人如果能把他的感觸和他的朋友們共享，縱然無酒，也是愉快的。
聰明的主人都知道，用笑來款待客人，遠比用豐盛的酒菜更令人感激。
一個人往往會在最奇怪的時候、最奇怪的地方，和一個最想不到的人變成朋友 ，
甚至他們自己都不知道這種情感是怎麼來的。
LONG);
	setup();
	replace_program(ROOM);
}
