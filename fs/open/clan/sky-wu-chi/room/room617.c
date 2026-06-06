inherit ROOM;
void create() {
	set( "short", "ddt雜物間-6" );
	set( "owner", "cong" );
	set( "build", 10268 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room616",
		"south"     : "/open/clan/sky-wu-chi/room/room614.c",
	]) );
	set( "long", @LONG
這裡舉目所見都是一大堆的廢物你試圖從這一堆東西中找出
有用的寶物，不過這顯然是個很大的挑戰但你還是不死心的努力
終於在一番搜尋之下你找到了一罐純喫茶，先喝一口茶再來找找
或許才是一個好方法，你深深的喝了一大口，呼~真是透心涼阿
LONG);
	setup();
	replace_program(ROOM);
}
