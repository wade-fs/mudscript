// Room : /open/clan/sky-wu-chi/room/room110.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
        set( "long", @LONG
走進來一看，這裡是$HIR$阿嚕米$NOR$休息的寢室，雖然他正在外
面討論任務，但是仍可以看見整齊劃一的房間擺設，一旁的
櫃子裡好像有幾件重要的$HIY$殺手裝備$NOR$，你正想多看幾眼突然外
面傳來一陣聲音：小子，別亂偷看！快給我滾出去！
LONG);
        set( "cmkroom", 1 );
        set( "no_clean_up", 0 );
	set( "short", "$BMAG$$HIG$阿嚕米的臥室$NOR$" );
	set( "owner", "cong" );
	set( "object", ([
		"file9"    : "/obj/stone/suipian",
		"amount9"  : 41,
	]) );
	set( "build", 10205 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room155.c",
		"north"     : "/open/clan/sky-wu-chi/room/room209.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"west"      : "/open/clan/sky-wu-chi/room/room196.c",
	]) );
        set( "clan_room", "天道無極" );
	set( "light_up", 1 );
        set( "no_transmit", 1 );
        setup();

        }


