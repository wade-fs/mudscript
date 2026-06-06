inherit ROOM;
void create() {
	set( "short", "$HIG$藥$HIR$之$HIC$藏$NOR$" );
	set( "owner", "skyent" );
	set( "object", ([
		"file5"    : "/obj/gift/xiandan",
		"file3"    : "/open/fire-hole/obj/b-pill",
		"file4"    : "/obj/gift/shenliwan",
		"file2"    : "/open/capital/guard/gring",
		"file6"    : "/obj/gift/hobowdan",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount1"  : 2010,
		"file1"    : "/open/fire-hole/obj/y-pill",
		"file8"    : "/open/ping/questsfan/obj/diamond_belt",
		"amount3"  : 255,
		"amount6"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10735 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room297",
		"south"     : "/open/clan/ou-cloud-club/room/room4",
	]) );
	set( "long", @LONG
此處就是當今聖上欽賜給傲雲山莊的大內御醫〔$HIW$風$HIR$火$HIM$山$HIG$林$NOR$〕的
煉藥房，進入此房只有陣陣撲鼻而來的刺鼻味道，而在你眼前所見
到的也就是當今武林極為少數的珍貴草藥，還有許多的丹藥放在門
後的大櫃中，櫃上貼著一封條，字條上寫明：$BRED$$HIW$偷藥者，殺無赦！！$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
