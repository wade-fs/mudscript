inherit ROOM;
void create() {
	set( "short", "龍王室" );
	set( "owner", "mill" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 300,
		"amount7"  : 300,
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 300,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount4"  : 300,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 300,
		"amount2"  : 300,
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 300,
		"amount10" : 300,
		"amount5"  : 300,
		"amount6"  : 300,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file7"    : "/open/mogi/castle/obj/ninepill",
	]) );
	set( "build", 10027 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room530",
	]) );
	set( "long", @LONG

　　此處存放著珍貴的龍王精元，乃由火龍幻界的統治者－－火龍王
身上取出的。而火龍王所居住的地方，雄雄的火燄長年燃燒，似乎想
燒盡世間所有的一切。因此從龍王身上取出的精元，服下一顆後，便
可幫你抵擋那雄雄火燄，是為前往火龍幻界的必需品。

LONG);
	setup();
	replace_program(ROOM);
}
