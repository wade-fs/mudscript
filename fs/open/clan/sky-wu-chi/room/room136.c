inherit ROOM;
void create() {
	set( "short", "空瓶子臥房" );
	set( "object", ([
		"amount7"  : 1,
		"file3"    : "/open/killer/obj/knife",
		"file6"    : "/open/dancer/obj/yuawaist",
		"amount1"  : 46302,
		"amount2"  : 16745,
		"amount8"  : 1,
		"file2"    : "/open/killer/obj/needle",
		"file7"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount4"  : 46330,
		"file8"    : "/open/mogi/castle/obj/seven5-dark-head",
		"file5"    : "/open/killer/obj/lustar",
		"file1"    : "/open/killer/obj/knief3",
		"amount3"  : 66410,
		"amount6"  : 1,
		"amount5"  : 74076,
		"file4"    : "/open/killer/obj/knief2",
	]) );
	set( "light_up", 1 );
	set( "build", 12000 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room137.c",
		"south"     : "/open/clan/sky-wu-chi/room/room134.c",
		"east"      : "/open/clan/sky-wu-chi/room/room133",
		"north"     : "/open/clan/sky-wu-chi/room/room135.c",
	]) );
	set( "long", @LONG
這裡是這整個莊院的主人空瓶子的臥室，裡面樸素的自然，一點
也沒有像是擁有絕世武學及廣大的莊院的的人所應該有的華麗，簡單
的一張大理石圓桌及雙人通舖外，其它的都不值一提。唯一特別的是
牆上所掛的一對爪子，像是有點像動物一樣的爪子，但是顏色卻是有
如黃金般的讓人感覺此物必定來自天外之物所有，且像是有靈性般的
當你一走進來時居然發出嗡嗡嗡的聲響。似乎對你的闖入感到有種威
脅而要做反擊的聲音。

LONG);
	setup();
	replace_program(ROOM);
}
