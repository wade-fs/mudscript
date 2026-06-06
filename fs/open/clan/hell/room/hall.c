 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG



$RED$陰曹入口  $NOR$-
    你已經來到了陰間的入口。雖然距離地府還有一段距離，但是你已經
感受到陣陣刺骨的陰風。四周一片荒涼，但是卻鬼影幢幢，看來這邊的夜
總會蠻熱鬧的，應該不愁沒伴。南邊和上面好像是和人世間相通的管道，
不過好像有一股無形的力量隔開這兩個不同的世界，看來要從這兩個方向
回去不是那麼簡單的事情。

LONG);
	set( "short", "$HIR$你的眼前一黑﹐接著什麼也不知道了....$BLK$" );
	set( "item_desc", ([
		"煤油冥紙的屍體(corpse)" : @ITEM
這是一代豬神煤油冥紙,但是他已經死了,只剩下屍體在這裡
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10138 );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room3.c",
		"east"      : "/open/clan/hell/room/room7.c",
		"enter"     : "/open/clan/hell/room/room37.c",
		"west"      : "/open/clan/hell/room/room10.c",
		"up"        : "/open/clan/hell/room/room23.c",
		"south"     : "/open/clan/hell/room/room42",
		"down"      : "/open/clan/hell/room/room8.c",
	]) );
	setup();                                             
	call_other( "/obj/board/hell_b", "???" );
	}
