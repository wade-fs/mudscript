inherit ROOM;
void create() {
	set( "short", "蘭花園" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/seven1-dark-head",
		"amount10" : 1,
		"file9"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount8"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file6"    : "/open/mogi/castle/obj/seven7-dark-head",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount1"  : 8,
		"file8"    : "/open/mogi/castle/obj/seven3-dark-head",
		"file1"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file7"    : "/open/mogi/castle/obj/seven4-dark-head",
		"amount6"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount9"  : 1,
	]) );
	set( "owner", "mill" );
	set( "build", 10009 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room155.c",
	]) );
	set( "long", @LONG

　　蘭花的高貴與芬芳，總是讓人流漣，蝴蝶總是在美麗的花朵上駐
足，而辛勤的蜜蜂則努力的工作著，蟲鳴鳥叫讓人感覺恬靜舒適。除
了蘭花外還種植著許多的花朵與樹木，這裡除了奇花異草外，還有許
多珍禽異獸，讓你忍不住停下腳步，欣賞眼前的美景。

LONG);
	setup();
	replace_program(ROOM);
}
