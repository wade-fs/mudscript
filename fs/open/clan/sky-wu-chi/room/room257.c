inherit ROOM;
void create() {
	set( "short", "小昭的窩" );
	set( "owner", "sblade" );
	set( "build", 10733 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room299.c",
		"west"      : "/open/clan/sky-wu-chi/room/room363",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
這兒就是小昭的房間，在這裡有一種令人十分舒服的感覺，地上鋪設著虎皮條紋的地毯，顯示出這裡主人的風格，牆上掛著一張真人般大小的女人照片，下面寫著幾個字~$HIR$我的達令$NOR$~，在你的左手邊有一個水族箱，裡面養的魚你從來都沒有看過，右邊的原木地板上還放滿了柔軟的懶骨頭和可愛的蠶絲抱枕，涼風夾帶著淡淡的桂花清香從後方的院子裡徐徐的吹來，而飄逸的落地白紗窗簾外，溫暖的金色陽光正與蝴蝶翩翩起舞，真是一個優閒慵懶、適合大家聚在一塊兒細細品茶、談天說地的午后...。
LONG);
	setup();
	replace_program(ROOM);
}
