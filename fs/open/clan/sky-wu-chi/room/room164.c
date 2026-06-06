inherit ROOM;
void create() {
	set( "short", "如夢似幻" );
	set( "owner", "pigpana" );
	set( "light_up", 1 );
	set( "build", 13208 );
	set( "object", ([
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount10" : 1,
		"amount6"  : 1,
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"file8"    : "/daemon/class/blademan/obj/six-neck",
		"amount8"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/tendo/obj/chaosbelt",
		"file10"   : "/obj/gift/unknowdan",
		"amount1"  : 1,
		"amount9"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file9"    : "/daemon/class/blademan/obj/six-neck",
		"amount5"  : 1,
		"file4"    : "/daemon/class/blademan/obj/shield",
		"file7"    : "/obj/gift/bingtang",
	]) );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room69",
	]) );
	set( "long", @LONG
正當你踏進這個房間之時,忽然間雷聲大響,瞬間一道閃電已經
劈在你身上,將你的護身氣勁全數打散,在此同時傳來陣陣齒輪轉動
的聲響,轉眼間,已經是一陣暴雨,將你淋的一身濕,就在你還搞不清
楚狀況的時候,卻忽然驚覺!一切都是幻覺,不禁讓你想馬上離開這
個恐怖又奇幻的地方.

LONG);
	setup();
	replace_program(ROOM);
}
