inherit ROOM;
void create() {
	set( "short", "FS龍來靈骨塔" );
	set( "owner", "ctx" );
	set( "object", ([
		"amount9"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"file6"    : "/obj/gift/shenliwan",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"file3"    : "/obj/gift/shenliwan",
		"file7"    : "/obj/gift/shenliwan",
		"amount10" : 1,
		"amount8"  : 1,
		"file10"   : "/obj/gift/shenliwan",
		"file2"    : "/obj/gift/shenliwan",
		"amount7"  : 1,
		"file8"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/shenliwan",
		"amount2"  : 1,
		"file4"    : "/obj/gift/shenliwan",
		"amount6"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10089 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room495",
	]) );
	set( "long", @LONG
這裡就是全FS獨一無二的納骨塔了, 看到上面擺的一罈罈的
骨灰,就知道這邊是做什麼的,選擇火葬的棺木在經過火葬場處理
後就在此供奉, 理論上放在靈骨塔會比在公墓土葬來的有較高的
空間使用效率吧,不過在這邊似乎好像感覺不太出來,大概是硬碟
夠大的原因吧。

LONG);
	setup();
	replace_program(ROOM);
}
