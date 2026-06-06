inherit ROOM;
void create() {
	set( "short", "$HIG$CPU的閨房$NOR$" );
	set( "object", ([
		"file1"    : "/open/killer/obj/hate_knife",
		"amount1"  : 3483708,
	]) );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room142",
		"south"     : "/open/clan/sky-wu-chi/room/room151.c",
	]) );
	set( "light_up", 1 );
	set( "build", 12000 );
	set( "long", @LONG
這裡是『空瓶子』的地底練功場所。並沒有怎樣的特別，只是有一張床
罷了。你走過去摸了一下，嚇到了。原來那是張萬年寒冰床，且在看其冰床
的中間沒想到居然會是引那『飛來峰』上的熔岩，你開始感到這位主人的威
力了。到了這裡你卻只有一個念頭，那就是趕緊逃跑，以免被這位主人所發
現，而把你殺人滅口。以免你知道太多。但是你確定你有辦法能夠跑出這個
地方嗎，我不禁的懷疑了起來。
LONG);
	setup();
	replace_program(ROOM);
}
