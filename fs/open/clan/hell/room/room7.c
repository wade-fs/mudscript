inherit "/open/clan/claneqshop.c";  
void create() {
	set( "short", "$HIG$兵器裝備存放處(稀奇的東東)$NOR$ " );
	set( "light_up", 1 );
	set( "no_clean_up", 1 );   
	set( "build", 10041 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/hall",
	]) );
	set( "long", @LONG
一個又大又寬敞的兵器房,房間的四周卦滿著林林總總的刀槍劍爪,由於地府
的幫眾都擁有一定的實力,所以通常市不必用到此處低階的存放室的,但是為了未來
招收的新幫眾著想,地府仍然建立這個一般兵器收藏室,希望地府的幫眾在離開的
的時候能將身上不必的裝備拿來此處放置

LONG);
	setup();
}
