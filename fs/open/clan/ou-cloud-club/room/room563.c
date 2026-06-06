inherit ROOM;
void create() {
	set( "short", "$HIC$蟲穴" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/obj/gift/hobowdan",
	]) );
	set( "build", 2736 );
	set( "owner", "ttt" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room82",
	]) );
	set( "long", @LONG
一踏入此地‧‧‧便有一股傲情俠骨的氣息朝你直撲而來
‧‧‧原來這便是傳說中仙意靈地的傲雲山莊，據說當年乃此
莊主劍君十二恨召集武林上赫赫有名的雪蒼、瀧山、聖火、仙
劍、儒門、段家、舞者、殺手、惡人、魔刀、金刀的各派的第
一強者，窮盡畢生功力合力所創出來的空間，而莊主也為了武
林的安危，便立下重誓，要幫眾一生除惡懲奸，如此情操早已
令傲雲山莊成為全天下第一大幫了‧‧‧




LONG);
	setup();
	replace_program(ROOM);
}
