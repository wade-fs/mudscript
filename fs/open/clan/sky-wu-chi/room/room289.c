inherit ROOM;
void create() {
	set( "short", "風雁" );
	set( "owner", "cong" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room291",
	]) );
	set( "long", @LONG
當你走進這個房間時你突然覺得背後有人似的渾身毛骨悚然
突然你覺得有人正以千里傳音和你說話....
頓時你才知道幫主燕仔的驚事修為以達天人
從此無反叛知心...只肯為幫主效命
過了一年後江湖傳出了一個新的傳說...雪雁一出誰與爭鋒
LONG);
	setup();
	replace_program(ROOM);
}
