inherit ROOM;
void create() {
	set( "short", "奪命谷" );
	set( "owner", "evonne" );
	set( "build", 10002 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room653",
	]) );
	set( "long", @LONG
此處位於寒冷高原的入口山腰，狹窄的通道使得狂風更加猛烈，吹的讓
人睜不開眼睛，兩旁的山壁上光禿禿的樣子，沒有植物能夠在上面生存，不
時還有小石頭從上面滾下來，讓人心驚膽跳的不時抬頭觀望，害怕被落石擊
中無法全身而退，此處又名『奪命谷』，可見此處地勢的險峻。

LONG);
	setup();
	replace_program(ROOM);
}
