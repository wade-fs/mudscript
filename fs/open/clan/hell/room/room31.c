inherit ROOM;
void create() {
	set( "short", "憤怒之拳" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/daemon/class/fighter/figring",
	]) );
	set( "light_up", 1 );
	set( "build", 11926 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room28",
	]) );
	set( "long", @LONG
相傳閻羅王曾有一次極怒之時,再地府擊出一拳,型成前方這個前方這個山洞
從此只要是武者所用的相關武器都會被存放在此,由於此第本無地名,故陰間的鬼
民們便以當初建成的原因命名,取名為憤怒之拳,以紀念當初驚動天地的威力,表
達對閻羅王的尊敬之意

LONG);
	setup();
	replace_program(ROOM);
}
