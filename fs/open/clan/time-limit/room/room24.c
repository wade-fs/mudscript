inherit ROOM;
void create() {
	set( "short", "$BGRN$校園$BCYN$一景$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room83.c",
		"west"      : "/open/clan/time-limit/room/room80",
		"south"     : "/open/clan/time-limit/room/room81.c",
		"north"     : "/open/clan/time-limit/room/room82.c",
		"down"      : "/open/clan/time-limit/room/room9",
	]) );
	set( "long", @LONG
學生在上課之餘,有時也會到校園裡散散步,碧草如茵的草地上坐著
幾個學生,仰望著天空那朵看起來像狗的雲,一旁的水池流著清澈的水,
彷彿可以洗淨心靈的塵埃,水池上的石碑刻著霍格華茲歷屆校長的名字,
不遠處的大樹下幾名學生追逐嘻戲,幾名學生坐著看書,並拿出魔杖練習魔法

LONG);
	setup();
	replace_program(ROOM);
}
