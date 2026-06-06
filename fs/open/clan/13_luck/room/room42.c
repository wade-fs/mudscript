inherit ROOM;
void create() {
	set( "short", "客棧右廳" );
	set( "object", ([
		"file7"    : "/daemon/class/blademan/obj/skykey",
		"amount8"  : 1,
		"amount2"  : 1,
		"file3"    : "/daemon/class/blademan/obj/wstone",
		"file5"    : "/daemon/class/blademan/obj/wastone",
		"amount1"  : 1,
		"amount5"  : 1,
		"file1"    : "/daemon/class/blademan/obj/gstone",
		"amount6"  : 1,
		"amount4"  : 1,
		"file6"    : "/daemon/class/blademan/obj/hstone",
		"file8"    : "/obj/gift/hobowdan",
		"amount7"  : 1,
		"amount3"  : 1,
		"file2"    : "/daemon/class/blademan/obj/fstone",
		"file4"    : "/daemon/class/blademan/obj/estone",
	]) );
	set( "build", 10901 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room40.c",
		"望月樓"    : "/open/clan/13_luck/room/room114.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    歡迎您來到十三吉祥的客棧右廳，請先向櫃檯的店小二CHECK IN
辦理好手續後，您就可以回到妳的廂房休息了，如有需要任何服務請
直撥CT頻道將有專人為您服務～～
                                               謝謝光臨 ！！

             
               從這往前走，即是『望月樓』。
             
LONG);
	setup();
	replace_program(ROOM);
}
