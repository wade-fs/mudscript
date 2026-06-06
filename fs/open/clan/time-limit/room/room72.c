inherit ROOM;
void create() {
	set( "short", "$BGRN$貓$BYEL$頭$BBLU$鷹$BCYN$室$NOR$" );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room73",
	]) );
	set( "long", @LONG
貓頭鷹是巫師的信差,而學生們也可以擁有自己的貓頭鷹,
因此學校設置個貓頭鷹的休息室,貓頭鷹可以在這裡睡覺,
肚子餓時可以去禁忌森林打獵,需要送信時也可以馬上出發,
不過一大群貓頭鷹在一起,衛生得要做好控管,免得傳染禽流感就麻煩了

LONG);
	setup();
	replace_program(ROOM);
}
