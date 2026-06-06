inherit ROOM;
void create() {
	set( "short", "$HIR$劍塚$NOR$" );
	set( "owner", "radio" );
	set( "light_up", 1 );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file1"    : "/open/gsword/obj/dragon-sword",
	]) );
	set( "build", 11804 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room28.c",
	]) );
	set( "long", @LONG
這裡是天下劍客手中之劍的最終去處,當主人以死,劍靈便會被閻羅王招至此處
以此為墳,閻羅王也常將他從四處搜羅回來的神劍收藏於此處,所以正常人踏進此處
不但會馬上立感劍氣沖天,若有修為不夠深厚者,甚至會被此處的劍氣所傷,相傳閻羅
王想收集全天下奇劍,盡藏於此

LONG);
	setup();
	replace_program(ROOM);
}
