inherit ROOM;
void create() {
	set( "short", "夢幻武道場" );
	set( "owner", "trumpet" );
	set( "object", ([
		"file5"    : "/open/fire-hole/obj/w-pill",
		"amount9"  : 3,
		"file4"    : "/open/mon/obj/mon-pill",
		"file9"    : "/open/ping/obj/poison_pill",
		"amount4"  : 50,
		"file2"    : "/obj/stone/powder",
		"amount5"  : 5,
		"amount3"  : 3,
		"amount1"  : 5,
		"file3"    : "/obj/stone/suipian",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 23,
	]) );
	set( "build", 11144 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
剛走進這個道場你馬上就被強烈的肅穆之氣所震攝，這裡的地板是用
上好的檜木所作成，正中央的牆壁上掛著一副巨大的「武」字，字體蒼健
有力，隱約還帶著代表武學至高境界的以武入字的氣勢，左右兩邊牆上分
別又寫有「道」與「心」兩幅大字，可見這間道場的主人一定是個武學宗
師，才能徹底通曉武學與修心養性間不可分的關聯。這個道場雖然佈置簡
單，但是在隱約中流露出的霸者氣息卻令你印象十分深刻。

LONG);
	setup();
	replace_program(ROOM);
}
