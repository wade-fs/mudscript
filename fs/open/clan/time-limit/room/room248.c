inherit ROOM;
void create() {
	set( "short", "$HIG$臭$HIY$虫$HIC$倉$HIM$庫$NOR$" );
	set( "light_up", 1 );
	set( "owner", "rena" );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room204",
	]) );
	set( "long", @LONG
    $HIW$這是一間$HIM$坪數$HIW$非常大的$HIR$倉庫$HIW$!!
裡面放著許多的東西..有$HIG$寶物$HIW$包括一堆$HIC$廢物$HIW$..
這一堆$HIR$戰利品$HIW$都是靠著$HIY$打鬥$HIW$收集回來的--
東西$HIC$堆積如山$HIW$,隨時有$HIB$倒塌$HIW$的危機@@
也正因為如此..其中也有很多派的上用場的$HIC$好物
$HIW$只要$HIG$仔細尋找$HIW$...必能找到想要的東西..CCC
LONG);
	setup();
	replace_program(ROOM);
}
