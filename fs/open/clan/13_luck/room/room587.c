inherit ROOM;
void create() {
	set( "short", "新區域" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"northeast" : "/open/clan/13_luck/room/room588",
	]) );
	set( "long", @LONG
木影叢叢，森然羅列，草木輕揚於風中，木燃落魂魄有感於此身形微動隨意發出 
           
            ----===≡◎ 木影森羅式 ◎≡===----
                   『木光流鶯．驚天鳴』
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )

LONG);
	setup();
	replace_program(ROOM);
}
