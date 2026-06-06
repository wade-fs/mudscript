inherit ROOM;
void create() {
	set( "short", "$HIC$思量之家$HIW$內房$NOR$" );
	set( "owner", "salicili" );
	set( "light_up", 1 );
	set( "build", 29244 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room312",
		"west"      : "/open/clan/sky-wu-chi/room/room41",
	]) );
	set( "object", ([
		"amount9"  : 11,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/obj/gift/shenliwan",
		"file9"    : "/open/fire-hole/obj/k-pill",
		"amount2"  : 1,
		"amount6"  : 1,
		"file1"    : "/daemon/class/bonze/puty_pullium",
		"amount10" : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/dancer/obj/yuawaist",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"file2"    : "/open/dancer/obj/linrboots",
		"file8"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
	]) );
	set( "long", @LONG
房內擺著$HIG$烏木有束腰鼓腿彭牙梅花凳$NOR$,
............$HIR$紅木六開光雕拐子龍紋鼓墩$NOR$,
............$HIW$黑白萬花嵌螺鈿酸枝木小圓桌$NOR$,
雖說$HIW$思量$NOR$只是個小小副幫主,
這房內的擺置簡直可比帝王之家的還享受,
一陣腳步聲急行而來,
是誰,竟然沒經思量同意逕行闖入,
原來是老大$HIC$燕仔$NOR$,
燕仔一看房內,被屋內閃閃發亮的家俱刺的張不開眼,
呆了半餉,終於回過神來喝道{哇咧!幫款被你盜用多少? *_*}
LONG);
	setup();
	replace_program(ROOM);
}
