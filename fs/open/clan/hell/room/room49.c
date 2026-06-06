inherit ROOM;
void create() {
	set( "short", "$HIY$香蕉週刊$HIR$無靶兒$HIW$WC$NOR$" );
	set( "object", ([
		"file3"    : "/open/gblade/obj/dragon_book",
		"file1"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 40,
		"file5"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount4"  : 1,
		"amount2"  : 87,
		"amount5"  : 32,
		"amount3"  : 1,
		"file4"    : "/open/capital/obj/letter",
	]) );
	set( "owner", "blur" );
	set( "build", 11484 );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room34.c",
		"east"      : "/open/clan/hell/room/room136.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
香蕉週刊雖然沒有位女性員工...
但還是在公司外蓋了間女用WC
其實這間WC就是這本雜誌內容的最大供應商....
其實...香蕉週刊早就在推廣偷拍行.....
只是小璩的VCD被獨家標走...不然這次也給它大削一筆...
不過...根據大飛神秘友人透露可靠消息...
最近香蕉週刊拍到知名紅星天X(又名X心)的Bembem畫面...
相信不久後就會公諸於世....wahaha
LONG);
	setup();
	replace_program(ROOM);
}
