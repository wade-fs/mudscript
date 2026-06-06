inherit ROOM;
void create() {
	set( "short", "天雷" );
	set( "owner", "hild" );
	set( "object", ([
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount1"  : 55,
		"file3"    : "/open/mon/obj/thousand-nectar",
		"amount4"  : 53,
		"file1"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 36,
		"amount5"  : 43,
		"file7"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file6"    : "/open/fire-hole/obj/k-pill",
		"amount6"  : 8,
		"amount7"  : 8,
		"amount3"  : 1,
		"file4"    : "/open/mon/obj/mon-pill",
	]) );
	set( "build", 10065 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room168.c",
	]) );
	set( "long", @LONG
這房間充滿了五行八卦的排列法，仔細一看中間有個天雷雷石，是引發
陣行的關鍵，一想要走進去，忽然天雷勾動地火一發不可收拾，想要進
入這房間，除了要對易經八卦要有相當的瞭解，還要有抗幻的能力，要
不然一發動陣行，沒有人可以逃出這地方。就算平安無事，幻覺就會出
來。抗不了只有在這死的份。

LONG);
	setup();
	replace_program(ROOM);
}
