inherit ROOM;
void create() {
	set( "short", "議事殿堂-正殿" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file5"    : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"amount8"  : 1,
		"file3"    : "/obj/gift/xisuidan",
		"file4"    : "/open/magic-manor/obj/sun-heart",
		"amount10" : 1,
		"file9"    : "/open/killer/obj/soul-hands",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/killer/outsea/dstone",
		"file7"    : "/obj/gift/hobowdan",
		"amount5"  : 1,
		"amount3"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"file8"    : "/obj/gift/lingzhi",
	]) );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room387",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "light_up", 1 );
	set( "build", 10076 );
	set( "long", @LONG
這裡是白雪城的國家議事殿堂，環顧四方，一張花豹製成的毯子正鋪在地上，用
水晶砌成的桌子發出微微的紫光，而國王正坐在鑲著黃金的倚子上與大臣們討論
國家大事。勤快的僕人正在一旁伺候茶水，城堡的守衛正在這裡保護著國王。若
問起皇后在那兒呢?誰也不知道......
一位白雪城的臣子/minister/正在這兒與國王討論國家大事。
白雪城的國王/king/正在這理討論國家大事。
LONG);
	setup();
	replace_program(ROOM);
}
