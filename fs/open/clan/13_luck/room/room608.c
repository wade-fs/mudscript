inherit ROOM;
void create() {
	set( "short", "樹林" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room607",
		"south"     : "/open/clan/13_luck/room/room616",
	]) );
	set( "long", @LONG
草叢中開著一些不知名的小花，有紅的、黃的，還有紫的。樹林裏
光線暗淡，只能聽見頭頂上傳來一些鳥兒的啼鳴。偶而從茂密的葉間透
過的一線光伴著落葉在飛舞。朽木腐爛的氣味和身後傳來野獸的嘯聲使
人不覺猶豫了前進的腳步。林中立著一塊牌子(paizi)。
LONG);
	setup();
	replace_program(ROOM);
}
