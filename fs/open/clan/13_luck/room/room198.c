inherit ROOM;
void create() {
	set( "short", "無敵戰龍" );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room199",
	]) );
	set( "long", @LONG

這裡是無敵戰龍的龍尾部份，你是否已經準備好組合無敵戰龍了，若
是，請將龍末插入這條龍的龍尾吧！！！！你將九龍的魂魄引進無敵
戰龍的軀殼裡，龍腦放至戰龍的頭部，龍心放置戰龍的心窩，龍氣引
至戰龍體內，在將楓岩放置戰龍嘴巴。  
瞬間雷聲大作　地動山搖　無敵戰龍將要現世了　武林將是一場浩劫 

LONG);
	setup();
	replace_program(ROOM);
}
