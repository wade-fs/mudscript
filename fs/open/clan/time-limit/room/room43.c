inherit ROOM;
void create() {
	set( "short", "$BBLU$霍格$BMAG$華茲$BRED$銀行$NOR$" );
	set( "owner", "goldblade" );
	set( "object", ([
		"amount3"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"amount10" : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
	]) );
	set( "build", 10253 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room42.c",
		"west"      : "/open/clan/time-limit/room/room9.c",
		"pass"      : "/open/clan/time-limit/room/room44.c",
		"east"      : "/open/clan/time-limit/room/room40",
		"south"     : "/open/clan/time-limit/room/room41.c",
	]) );
	set( "long", @LONG
霍格華茲銀行是由古靈閣的妖精所開的分行,主要是提供學生提款和存款用,
另外也接受捐款,霍格華茲不以營利為目地,而基本的開銷還是有的,
此時就需要學生家長和外界巫師的協助,而且由妖精負責這項工作更是上上之選,
妖精不但聰明,還有強大的魔力,想欺騙妖精得要付出非常昂貴的代價
一旁可用呼嚕粉和古靈閣相通

LONG);
	setup();
	replace_program(ROOM);
}
