inherit ROOM;
void create() {
	set( "short", "草的裝備室" );
	set( "owner", "match" );
	set( "object", ([
		"amount2"  : 1,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/killer/obj/dagger",
		"amount1"  : 1,
		"file9"    : "/open/killer/obj/black",
		"amount10" : 1,
		"amount9"  : 424,
		"file10"   : "/obj/stone/jiao",
		"file8"    : "/open/killer/obj/bellstar",
		"file4"    : "/open/killer/obj/dagger",
		"amount8"  : 3363,
		"amount4"  : 1,
		"file2"    : "/open/killer/headkill/obj/world_dag",
		"file5"    : "/open/killer/headkill/obj/i_dag",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file7"    : "/obj/stone/powder",
		"file6"    : "/open/killer/headkill/obj/i_dag",
		"amount7"  : 61,
	]) );
	set( "light_up", 1 );
	set( "build", 10033 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room214",
	]) );
	set( "long", @LONG
這裡是草的裝備室，裡面存放了很多武器，專門供草出任務用。
草是專門使用匕首的高手，看到一旁擺放的絕世匕首，就會知道草不
是一個好惹的人物。看到排列整齊的裝備和武器，令你也不禁緊張了
起來，希望你不會是草下一個任務的對象。
LONG);
	setup();
	replace_program(ROOM);
}
