inherit ROOM;
void create() {
	set( "short", "財神到" );
	set( "owner", "cong" );
	set( "object", ([
		"amount8"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 1,
		"file9"    : "/open/common/obj/mass",
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount10" : 1,
		"amount4"  : 32,
		"file3"    : "/open/ping/obj/poison_pill",
		"amount3"  : 10,
	]) );
	set( "build", 10185 );
	set( "light_up", 1 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
啪! 的一聲..一疊銀票掉到你的面前,你伸手去捉,卻撲了個空,原來只是南柯一夢
唉!!!錢難賺,兒子又年輕,老婆又花的兇,到底是人在賺錢,還是人被錢給賺去了
你摸摸頭,無奈的躺回床上,繼續做大頭夢,看還有沒有從天而降的禮物
,可以讓自己少奮鬥個三十年.
LONG);
	setup();
	replace_program(ROOM);
}
