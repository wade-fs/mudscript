inherit ROOM;
void create() {
	set( "short", "『桃花森林』 " );
	set( "owner", "mill" );
	set( "object", ([
		"amount1"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file7"    : "/obj/gift/unknowdan",
		"amount9"  : 1,
		"amount10" : 1,
		"file6"    : "/obj/gift/unknowdan",
		"file8"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"file2"    : "/obj/gift/unknowdan",
		"amount4"  : 1,
		"file9"    : "/obj/gift/lingzhi",
		"file10"   : "/obj/gift/bingtang",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/unknowdan",
		"file3"    : "/obj/gift/shenliwan",
	]) );
	set( "build", 10056 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room260",
		"north"     : "/open/clan/13_luck/room/room247.c",
	]) );
	set( "long", @LONG
再走進桃花林裡，依稀聽見遠方傳來稀稀蘇蘇的聲音。對於剛剛很多的
岔路就不太那麼在意了。只是在桃花林裡的出口好像有點過多，感覺似乎是
有人故意排這個陣局的，但是這只是個虛晃的手法而已，堅持下去將會走出
這片桃花林。
LONG);
	setup();
	replace_program(ROOM);
}
