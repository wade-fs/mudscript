// Room : /open/clan/demon_castle/room/hall.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", ""); new("/obj/gift/xisuidan.c")->move(find_player("neverend")); //" );
	set( "item_desc", ([
		"map" : @ITEM
                                             齊天殿  
                                               ∣
                            白虎堂           青龍殿           朱雀堂
                              ∣               ∣               ∣
                             堂口－青龍迴廊－青龍殿－青龍迴廊－堂口
                                               ∣
  芙櫻泉                                     綺玉門
    ∣                                         ∣
 水之神殿                                   皇城大道
    ∣                                         ∣
  芙櫻流─芙櫻流─芙櫻流─映水門─皇城水路  皇城大道
                                     ∣        ∣
                                  皇城水路－皇城大道
                                               ∣
                                            皇城大道
                                               ∣     
                 秋陽流─吉祥水道─吉祥水道─柳月泉─詠泉亭─吉祥林道─吉祥林道─霧之林入口
                   ∣                          ∣
  吉祥水道入口－吉祥水道                     武器室

ITEM,
	]) );
	set( "exits", ([ /* sizeof() == 5 */
		"west"      : "/open/clan/13_luck/room/room3.c",
		"east"      : "/open/clan/13_luck/room/room2.c",
		"south"     : "/open/clan/13_luck/room/room5.c",
		"up"        : "/open/clan/13_luck/room/room9.c",
		"enter"     : "/open/clan/13_luck/room/room136.c",
		"north"     : "/open/clan/13_luck/room/room4.c",
	]) );
	set( "build", 13822 );
	set( "light_up", 1 );
	set( "no_transmit", 1 );
	set( "long", @LONG

    柳月泉裡總是無時無刻的散發出如柳月般的淡淡金光，金光總隨著
泉水起起伏伏，也讓四周的景物閃閃發亮，彷彿是人間仙境。且柳月泉
也是十三吉祥的中心點，是進出皇城的必經之地，而且也是讓大家溝通
意見的地方，如果你想知道十三吉祥的地圖可以觀看一下地圖(map)。

LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	setup();
	call_other( "/obj/board/13_luck_b", "???" );
	
	}
