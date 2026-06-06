inherit ROOM;
void create() {
	set( "short", "瑤光堂大廳" );
	set( "owner", "aaabc" );
	set( "build", 11748 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room522",
		"north"     : "/open/clan/13_luck/room/room511",
	]) );
	set( "long", @LONG
你冒著必死的決心來到了瑤光堂，你看到華琉衣就站在大廳的正中
間，他雙眼注視著四周好像有事情要發生的樣子，身後站著袁冬曲，她
身上散發出一股濃濃的殺氣，仿佛就置身在戰場上一樣。而廳堂兩旁陳
列著許多上等檀木打造的太師椅，看似整齊，其實是依五行八卦陣排列
。四周看去，如此排場，心裡不免一陣讚嘆。
LONG);
	setup();
	replace_program(ROOM);
}
