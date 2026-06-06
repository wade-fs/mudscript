inherit ROOM;
void create() {
	set( "short", "桃花島" );
	set( "owner", "asfd" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room262.c",
	]) );
	set( "long", @LONG

    名震江湖一時的桃花島，傳說中的五大高手都曾來過這裡，也都在這
裡的山壁上留了一招曠世絕學，想想當年的五大高手，每個都身負絕學，
能在這學個一招半式的話，出去就已經是個數一數二的高手了，想到如此
，心裡不免癢癢的想進去偷看偷學一番，不過聽說好像十個人進去沒有一
個可以走的出來，不過又想到楊大俠當年的黯然銷魂掌，心裡便想著死就
死，進去吧!

LONG);
	setup();
	replace_program(ROOM);
}
