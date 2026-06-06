// Room : /open/clan/sky-wu-chi/room/room3.c
 inherit "/open/clan/claneqshop.c";

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "long", @LONG
寒風山莊，看似清寒極冷，實際上卻是一個鳥語花香的別墅
沒有那冬寒，又哪來的別樹一格的獨特溫馨，這裡不但沒有那刺
骨的寒風，也沒那擾耳的風戾聲，只那寒若冰的外觀下，有著大
家喜悅的歡笑聲，以及那人情似暖的友情下，共同建立的大家庭
而以。
LONG);
	set( "short", "$HIC$寒泉穴$NOR$" );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "build", 27 );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "no_clean_up", 1 );
	set( "item_desc", ([ /* sizeof() == 2 */
  "ll" : "",
  "sign" : "放武器或防器請打:    put  XXXXX
拿武器或防器請打:    take XXXXX


此處拿放還未完成...請大家加油完成100間ROOM^^
",
]) );
	set( "eqroom", 1 );
	setup();

	}
