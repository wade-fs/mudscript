inherit ROOM;
void create() {
	set( "short", "議事殿堂" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount4"  : 1,
		"file1"    : "/obj/gift/unknowdan",
		"amount6"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"amount7"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"file7"    : "/obj/gift/shenliwan",
		"file6"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"amount3"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"file2"    : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"file3"    : "/obj/gift/unknowdan",
		"amount8"  : 1,
		"amount1"  : 1,
		"file4"    : "/obj/gift/xiandan",
		"amount2"  : 1,
	]) );
	set( "build", 10909 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room100",
		"south"     : "/open/clan/sky-wu-chi/room/room390.c",
		"up"        : "/open/clan/sky-wu-chi/room/room385.c",
	]) );
	set( "long", @LONG
這裡是白雪城的國家議事殿堂，環顧四方，一張花豹製成的毯子正鋪在地上，用
水晶砌成的桌子發出微微的紫光，而國王正坐在鑲著黃金的倚子上與大臣們討論
國家大事。勤快的僕人正在一旁伺候茶水，城堡的守衛正在這裡保護著國王。若
問起皇后在那兒呢?誰也不知道......
LONG);
	setup();
	replace_program(ROOM);
}
