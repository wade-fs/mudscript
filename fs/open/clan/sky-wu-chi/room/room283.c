inherit ROOM;
void create() {
	set( "short", "普通房間" );
	set( "owner", "hild" );
	set( "light_up", 1 );
	set( "build", 10008 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room179",
	]) );
	set( "long", @LONG
這房間跟是一間很普通的房間，向南看，看到有不少的刀，向東看
看到落雷，聽到恐怖的降雷聲，向西看，看到有許多的雕像，有白虎、
朱雀、玄武，這四大聖獸的排列位置讓人覺得有一種，是陣式的排列法
看來想要進去得要有強大的輕功能力，以及過人的智慧，才能安然度過
這間房間看來平凡，其實才是最不平凡的房間。原因如何下回分解。


LONG);
	setup();
	replace_program(ROOM);
}
