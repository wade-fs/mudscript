inherit ROOM;
void create() {
	set( "short", "$HIC$思量之家$HIW$EQ室三$NOR$" );
	set( "owner", "salicili" );
	set( "build", 11233 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room33",
		"east"      : "/open/clan/sky-wu-chi/room/room138",
	]) );
	set( "long", @LONG

難過　是因為悶了很久;是因為想了太多;是心理起了作用;;你說　苦笑常常陪著你;在一起有點勉強;該不該現在休了我;;不想太多　我想一定是我聽錯弄錯搞錯;拜託　我想是你的腦袋有問題;;隨便說說　其實我早己經猜透看透不想多說;只是我怕眼淚撐不住;;不懂　你的黑色幽默;想通　卻又再考倒我;說散　你想很久了吧？;我不想拆穿你;;當作　是你開的玩笑;想通　卻又再考倒我;說散　你想很久了吧？;敗給你的黑色幽默;我的認真敗給黑色幽默

LONG);
	setup();
	replace_program(ROOM);
}
