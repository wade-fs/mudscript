inherit ROOM;
void create() {
	set( "short", "筱築石室" );
	set( "owner", "sblade" );
	set( "object", ([
		"file1"    : "/open/firedancer/npc/eq/r_armbands",
		"file2"    : "/open/firedancer/npc/eq/r_boots",
		"amount2"  : 1,
		"amount1"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10004 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room364",
	]) );
	set( "long", @LONG
    這裡是【幽谷筱築】的裝備存放室，石壁上掛滿了許多金光
閃閃的武器跟防具，令人問不目不暇給，仔細一瞧，啊！！這不
是任正晴的陽焱臂環、鄭士欣的龍氣劍、劉全書的金鋼指環、段
雲的飄雲扇‧‧‧等人的傲世兵器，天ㄚ！什麼裝備都有！原來
這裡是讓幫眾們在外面打來的戰利品存放的地方
LONG);
	setup();
	replace_program(ROOM);
}
