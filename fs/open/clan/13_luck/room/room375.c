inherit ROOM;
void create() {
	set( "short", "鑄劍房" );
	set( "object", ([
		"amount5"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/capital/obj/4-2",
		"file8"    : "/open/capital/obj/4-3",
		"file10"   : "/open/capital/obj/4-4",
		"file3"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file1"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file2"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file5"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file4"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount3"  : 1,
		"amount1"  : 1,
		"file9"    : "/open/capital/obj/4-4",
		"file6"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount7"  : 1,
	]) );
	set( "owner", "roar" );
	set( "build", 10587 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room377",
	]) );
	set( "long", @LONG

    走進這裡只見前面有一大火爐，正鍛鍊著一把長劍。原來這裡是提
供十三吉祥內所有劍的來源，這裡所冶煉出來的劍雖稱不上是絕世兵鋒，
但給一般弟子使用已經是綽綽有餘了。若你需要一把隨身的武器，來這拿
一把劍防身也是不錯的。

LONG);
	setup();
	replace_program(ROOM);
}
