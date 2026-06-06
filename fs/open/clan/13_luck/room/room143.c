inherit ROOM;
void create() {
	set( "short", "二樓藏經閣" );
	set( "object", ([
		"amount4"  : 1,
		"file5"    : "/open/dancer/obj/magicbook",
		"file1"    : "/open/center/obj/gamble_book",
		"file6"    : "/open/doctor/obj/curebook",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/tendo/obj/book2",
		"amount3"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire_book",
		"file8"    : "/open/badman/obj/sword_book",
		"amount1"  : 1,
		"file2"    : "/open/capital/obj/stabber_book",
	]) );
	set( "build", 10620 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room141",
	]) );
	set( "long", @LONG

　　僅靠著昏暗的燭火照明，沿著樓梯往上走，你來到了二樓的藏經
閣。其裝潢擺飾也不是普通的豪華，一點也沒有閣樓狹隘的感覺，反
而有一股舒適之感。這裡的藏書不下於一萬本，就是消失於武林多時
的武功，也可在這找到其祕笈心法。

LONG);
	setup();
	replace_program(ROOM);
}
