inherit ROOM;
void create() {
	set( "short", "楓之舞室" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/capital/obj/book",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 1,
		"file2"    : "/open/killer/memory/static",
		"amount3"  : 2,
	]) );
	set( "owner", "intelii" );
	set( "build", 10305 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room273",
	]) );
	set( "long", @LONG

    傳說中的門派，變態舞者手中的武器，一身法術無人能敵，尤其是
玄冰護體，比移花接木，借力使力還要厲害，只要兩三下，就可以收一
收，好去陰間報到了，天火神雷術更是讓你狀況一堆，小心看到舞者就
是不要打就對了。

LONG);
	setup();
	replace_program(ROOM);
}
