inherit ROOM;
void create() {
	set( "short", "$HIR$通吃$HIC$小$YEL$築$NOR$" );
	set( "owner", "baby" );
	set( "object", ([
		"file5"    : "/open/wind-rain/obj/bird-blade",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/sun-heart",
		"file3"    : "/open/magic-manor/obj/lunar-heart",
		"amount7"  : 1,
		"file1"    : "/open/gsword/obj1/bbladeball",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount2"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/obj/sun-heart",
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/obj/sun-heart",
		"file4"    : "/open/gsword/obj1/bpball",
		"file10"   : "/open/gsword/obj/silver_sword",
		"amount5"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/obj/lunar-heart",
		"amount6"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10206 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room194.c",
		"west"      : "/open/clan/ou-cloud-club/room/room239",
		"north"     : "/open/clan/ou-cloud-club/room/room238.c",
	]) );
	set( "long", @LONG
門前右上方，掛著一塊匾仔細一看，字體歪歪斜斜，共寫有
「$HIR$通吃$HIC$小$YEL$築$NOR$」四字，刻劃甚新，必是新造之物。而這些字，說它
像烏龜爬的，亦不為過，就像老鼠用尾巴沾上墨汁在桌上打轉所
留下來似的，怪裡怪氣，無法想像。如果能有勇氣將這種烏龜爬
的字，掛出來的人，不是瘋子，想必也有點自我陶醉的狂人吧！
LONG);
	setup();
	replace_program(ROOM);
}
