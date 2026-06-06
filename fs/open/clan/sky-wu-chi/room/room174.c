inherit ROOM;
void create() {
	set( "short", "$HIC$咩 咩 澡 房$NOR$" );
	set( "owner", "roboo" );
	set( "object", ([
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file10"   : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/capital/obj/blade2",
		"file5"    : "/daemon/class/dancer/bee_flute",
		"file6"    : "/open/capital/guard/gring",
		"amount6"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10887 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room25.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
房內擺著$HIR$烏木有束腰鼓腿彭牙梅花凳$NOR$,
$HIC$紅木六開光雕拐子龍紋鼓墩$NOR$,
$HIW$黑白萬花嵌螺鈿酸枝木小圓桌$NOR$,
這房內的擺置簡直可比帝王之家的還享受,
雖說$HIW$思量$NOR$只是個小小副幫主,
燕仔一看喝道{哇咧!幫款被你盜用多少? *_*}
LONG);
	setup();
	replace_program(ROOM);
}
