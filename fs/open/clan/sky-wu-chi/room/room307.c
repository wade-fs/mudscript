inherit ROOM;
void create() {
	set( "short", "伊耳謎的小臥室" );
	set( "owner", "sblade" );
	set( "light_up", 1 );
	set( "build", 10250 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room299",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
這兒就是伊耳謎的小小天地了。迷人的音樂從 CD 音響裡輕輕傳來，
房間中央擺著一張小圓桌，桌上放了好多好多好多的又香又脆又甜
的餅乾和各種可口的西式小茶點...。 哇！好好吃好好吃的樣子，
口水都要流出來了！右邊的原木地板上還放滿了柔軟的懶骨頭和可
愛的蠶絲抱枕，涼風夾帶著淡淡的桂花清香從後方的院子裡徐徐的
吹來，而飄逸的落地白紗窗簾外，溫暖的金色陽光正與綠樹兒翩翩
起舞，真是一個優閒慵懶、適合大家聚在一塊兒細細品茶、談天說
地的午后...。
LONG);
	setup();
	replace_program(ROOM);
}
