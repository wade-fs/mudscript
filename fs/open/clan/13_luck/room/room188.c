inherit ROOM;
void create() {
	set( "short", "毒藥庫" );
	set( "object", ([
		"file9"    : "/open/scholar/obj/icefan",
		"amount1"  : 10077,
		"file1"    : "/obj/poison/rose_poison",
		"file6"    : "/open/snow/obj/figring",
		"amount4"  : 6163,
		"amount5"  : 1,
		"amount2"  : 9937,
		"amount6"  : 1,
		"file8"    : "/open/killer/headkill/obj/w_dag",
		"file3"    : "/obj/poison/five_poison",
		"file7"    : "/open/tendo/obj/chaosbelt",
		"amount3"  : 10386,
		"amount8"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/killer/headkill/obj/i_dag",
		"file4"    : "/obj/poison/faint_poison",
		"file2"    : "/obj/poison/dark_poison",
		"amount7"  : 1,
	]) );
	set( "build", 10049 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room187",
	]) );
	set( "long", @LONG
這裡一看便知道是一間用來儲存藥材的庫房，房間四周圍是一列
列年代久遠的架子，架子上則擺滿了許多破破爛爛的藥罐子，年
代久遠的架子擺上破破爛爛的藥罐子，讓人懷疑這間儲藏庫還有
人在使用維護嗎。  往東走可以回到毒人居。
LONG);
	setup();
	replace_program(ROOM);
}
