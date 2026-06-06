inherit ROOM;
void create() {
	set( "short", "小白菜的沉壁房" );
	set( "owner", "sski" );
	set( "object", ([
		"file8"    : "/open/love/obj/cloth1",
		"file1"    : "/open/killer/weapon/k_torch",
		"amount8"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10050 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room228",
	]) );
	set( "long", @LONG
這裡你進來一看,我想你就完全知道這裡是裝了什麼東西了
看到了一堆堆小小短短的匕首,而且感覺到他的寒氣..你不知
不覺就想要拿起來一看,嗯..原來這就是皇族的人才會有的獨
門武器叫沉璧(moon dagger)...你不禁的想拿起來試試看手
感..只是你好像拿不起來似的..因為這些匕首似有人性的樣子

LONG);
	setup();
	replace_program(ROOM);
}
