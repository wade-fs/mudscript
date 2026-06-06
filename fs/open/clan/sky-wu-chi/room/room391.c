inherit ROOM;
void create() {
	set( "short", "白雪大道" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount5"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/gblade/obj/sa-head",
		"amount6"  : 1,
		"file10"   : "/open/mogi/castle/obj/sspill",
		"file8"    : "/open/fire-hole/obj/y-pill",
		"file6"    : "/open/gblade/obj/sa-head",
		"amount1"  : 1,
		"amount8"  : 15,
		"amount10" : 13,
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/capital/obj/blade2",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount7"  : 1,
		"file5"    : "/open/ghost-hole/obj/fire-spirit",
	]) );
	set( "build", 10717 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room386",
		"west"      : "/open/clan/sky-wu-chi/room/room393.c",
		"north"     : "/open/clan/sky-wu-chi/room/room390.c",
	]) );
	set( "long", @LONG
這裡是通往白雪城的主要道路，路的兩旁種著高雅的樹木，一朵小花從天空中緩
緩的掉入你的掌心，仔細一看原來是白色的櫻花，其它掉落的花瓣鋪滿了整個道
路，使你不忍心踩上去，小心的避開它們。往北走你可以看到白雪城，往南則連
接著石子路。
LONG);
	setup();
	replace_program(ROOM);
}
