inherit ROOM;
void create() {
	set( "short", "麒麟大將軍府" );
	set( "owner", "poiiiiop" );
	set( "object", ([
		"file5"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"amount10" : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-shield",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"file4"    : "/open/sky/obj/lucky_grasslink",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount2"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount3"  : 1,
		"file9"    : "/open/wu/obj/armband",
	]) );
	set( "build", 10065 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room404.c",
		"north"     : "/open/clan/sky-wu-chi/room/room403",
		"south"     : "/open/clan/sky-wu-chi/room/room405.c",
		"east"      : "/open/clan/sky-wu-chi/room/room406.c",
		"down"      : "/open/clan/sky-wu-chi/room/room396.c",
	]) );
	set( "long", @LONG
半神半聖亦半仙 全儒全道是全賢 腦中真書藏萬卷 掌握文武半邊天 
       素璞平凡顯人性 還我本覺見明鏡 真空為是迎正道

        十年蹤跡走紅塵，回首青山入夢頻。
        紫綬縱榮爭及睡，朱門雖富不如貧。
        儒園結義數載情，手足相知玉潔清。
        回首漫漫憶往事，劍膽琴心伴苦行。

坐鎮中央、運籌千里，手持萬軍生殺大權，
人稱『川之雄鷹』的麒麟大將軍 - 素環真
LONG);
	setup();
	replace_program(ROOM);
}
