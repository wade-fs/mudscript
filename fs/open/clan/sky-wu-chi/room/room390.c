inherit ROOM;
void create() {
	set( "short", "白雪城的入口" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file6"    : "/open/mogi/castle/obj/seven1-dark-head",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/mogi/castle/obj/seven2-dark-head",
		"file7"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount5"  : 1,
		"file5"    : "/open/mogi/castle/obj/seven5-dark-head",
		"amount1"  : 1,
		"file2"    : "/open/mogi/castle/obj/seven1-dark-head",
		"amount9"  : 1,
		"file4"    : "/open/mogi/dragon/obj/dragon-head",
		"file3"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount2"  : 1,
		"file10"   : "/open/mogi/castle/obj/seven4-dark-head",
		"amount10" : 1,
		"amount3"  : 1,
		"file8"    : "/open/mogi/castle/obj/white-ghost-head",
		"file9"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount7"  : 1,
	]) );
	set( "build", 10147 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room391",
		"north"     : "/open/clan/sky-wu-chi/room/room387",
	]) );
	set( "long", @LONG
這裡是通往白雪城的主要道路，路的兩旁種著高雅的樹木，一朵小花從天空中緩
三層樓高的白雪堡，屋頂則插了一根針狀的圓柱，圓柱上立了一支旗竿，懸掛著
白雪國的國旗。在你的北邊是國家的議事大廳，往南你可以走出這個城堡。
一位維護城堡安全的守衛/castel guard/正在這裡誡備著。
一位維護城堡安全的守衛/castel guard/正在這裡誡備著。
LONG);
	setup();
	replace_program(ROOM);
}
