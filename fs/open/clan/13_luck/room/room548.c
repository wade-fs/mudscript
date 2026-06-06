inherit ROOM;
void create() {
	set( "short", "尊重" );
	set( "owner", "dfyw" );
	set( "object", ([
		"amount9"  : 200,
		"amount1"  : 1,
		"amount6"  : 1,
		"amount7"  : 16,
		"file10"   : "/open/mon/obj/mon-pill",
		"file2"    : "/open/mon/obj/thousand-nectar",
		"amount2"  : 26,
		"file9"    : "/open/mon/obj/mon-pill",
		"file5"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file4"    : "/open/doctor/pill/sky_pill",
		"file1"    : "/open/ghost-hole/obj/ground-spirit",
		"amount10" : 100,
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"file7"    : "/open/doctor/pill/sky_pill",
		"amount4"  : 330,
		"amount5"  : 26,
	]) );
	set( "build", 10044 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room552.c",
		"up"        : "/open/clan/13_luck/room/room560",
		"north"     : "/open/clan/13_luck/room/room553.c",
		"out"       : "/open/clan/13_luck/room/room549.c",
		"jump"      : "/open/clan/13_luck/room/room368",
		"east"      : "/open/clan/13_luck/room/room551.c",
		"down"      : "/open/clan/13_luck/room/room547.c",
		"south"     : "/open/clan/13_luck/room/room554.c",
	]) );
	set( "long", @LONG
男生在發展關係的同時能尊重對方的意願，能把主控權交給女生的才是
好男生。艾斯德講的是「兩個人在一起要學會尊重彼此的任何決定」。
意見不合可以溝通，因為無論從人權、人性來說，男女生都是站在平等
地位上的 。
我告訴朋友---尊重，是最重要的!
如果他(她)會尊重你，意即什麼都好，都是能商量的。
會把你放在平等地位上看待的這男生或女生就不會糟到哪裡去。
LONG);
	setup();
	replace_program(ROOM);
}
