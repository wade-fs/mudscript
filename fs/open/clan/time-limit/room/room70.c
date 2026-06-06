inherit ROOM;
void create() {
	set( "short", "$HIY$庭$HIR$園$NOR$" );
	set( "owner", "goldblade" );
	set( "object", ([
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount3"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10409 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room69",
		"east"      : "/open/clan/time-limit/room/room73.c",
	]) );
	set( "long", @LONG
庭園裡種了許多花草,還有許多樹木,其中有棵特別高大的樹-渾拼柳,
是棵非常珍貴的樹木,不過它的脾氣很壞,會主動攻擊人,
你看它的樹枝就會手臂一樣,隨時可以向你打過來,難怪它附近都沒有
任何人跡,妙麗的貓-歪腿則在一旁打呼,完全不把渾拼柳放在眼裡

LONG);
	setup();
	replace_program(ROOM);
}
