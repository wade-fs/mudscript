inherit ROOM;
void create() {
	set( "short", "血痕居-峨眉" );
	set( "owner", "holeman" );
	set( "build", 10324 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room518",
	]) );
	set( "long", @LONG

    飄雪穿雲入四川，蜀中獨秀峨眉顛。
    日出金頂觀雲海，捨身崖下邀神仙。
    醉仙亭上醉望月，風雨飄香舞翩翩。
    一葉知秋情瑟瑟，花逐流水意潺潺。
    落花有情水無意，水雲空留落花殘。
    堪破紅塵醒蝶夢，四象同歸悟佛禪。
    佛光普照濟世人，佛心慈佑渡人間。
    佛法無邊回頭岸，不滅不絕永流傳。
    本應不聞凡間事，身在世中離世難。
    斬妖除魔鬼祛盡，斷髮長伴青燈前。



LONG);
	setup();
	replace_program(ROOM);
}
