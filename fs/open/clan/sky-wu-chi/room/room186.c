inherit ROOM;
void create() {
	set( "short", "珍瓏室" );
	set( "owner", "jsa" );
	set( "object", ([
		"amount1"  : 1,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"file8"    : "/obj/gift/shenliwan",
		"amount4"  : 6,
		"amount3"  : 1,
		"file1"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"amount5"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"file3"    : "/obj/gift/hobowdan",
	]) );
	set( "build", 10006 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room188",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
此處乃是特為下棋而設計的棋室，紙門上圖畫著閒
雲野鶴，輕風徐徐添幾分豁達；進得室來卻不見繁瑣傢
俱擺設，房間正中置一石桌，桌上雕鑿出棋盤紋路，楚
河漢界車馬爭鋒，以水玉雕成的棋子晃著微微光暈，紅
黑二色的漆色分為兩軍逐鹿中原；桌下是幾張古樸的蒲
團，旁邊有幾個小几供放置香茗佳釀。
LONG);
	setup();
	replace_program(ROOM);
}
