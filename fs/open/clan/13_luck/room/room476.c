inherit ROOM;
void create() {
	set( "short", "沙漠狂爆" );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/center/obj/mechoufen-head",
		"file6"    : "/open/center/obj/mechoufen-head",
		"amount4"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/center/obj/mechoufen-head",
		"file4"    : "/open/center/obj/mechoufen-head",
		"file7"    : "/open/center/obj/mechoufen-head",
		"amount7"  : 1,
	]) );
	set( "owner", "zmud" );
	set( "build", 10009 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room481",
	]) );
	set( "long", @LONG

    眼前妳所看到的是一片荒涼的沙漠，四方的一眼望去，不時的狂風
吹起黃沙滾滾而來，遠方是一片茫然，何時會到西武林亦是個未知數，
隨著熱風著吹著，讓人有種暈眩的感覺，慢慢的越走越累，讓人產生了
幻覺，讓你以為前方有個綠州小鎮，不顧一切的往前跑。

LONG);
	setup();
	replace_program(ROOM);
}
