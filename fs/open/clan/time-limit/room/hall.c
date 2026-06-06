// Room : /open/clan/demon_castle/room/hall.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$BBLU$時$BMAG$空$BGRN$大$BYEL$廳$NOR$" );
	set( "object", ([
		"file6"    : "/open/common/obj/liz_meat",
		"file3"    : "/open/common/obj/liz_meat",
		"file7"    : "/open/scholar/obj/icefan",
		"amount5"  : 1,
		"file1"    : "/open/common/obj/liz_meat",
		"amount7"  : 1,
		"file4"    : "/open/common/obj/liz_meat",
		"file5"    : "/open/common/obj/liz_meat",
		"amount3"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/common/obj/liz_meat",
		"amount4"  : 1,
		"amount1"  : 1,
	]) );
	set( "exits", ([
		"down"      : "/open/clan/time-limit/room/room195",
		"south"     : "/open/clan/time-limit/room/room163",
		"up"        : "/open/clan/time-limit/room/room97.c",
		"east"      : "/open/clan/time-limit/room/room2.c",
		"west"      : "/open/clan/time-limit/room/room20.c",
		"north"     : "/open/clan/time-limit/room/room3.c",
	]) );
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
	set( "build", 15638 );
	set( "light_up", 1 );
	set( "no_transmit", 1 );
	set( "long", @LONG
時空秘境是武林最神秘的幫派,在這裡可能會因為時空轉換的關係
而被傳送到不同時空的區域,每個時空都有其秘密,只要仔細觀察,
必定可以瞧出端倪,當初幫主就是為了讓幫眾進入不同的時空
來進行前所未有的冒險,特地進行時空壓縮,而到底會被傳送到哪裡去,
連幫主自己也不知道,不過這不也是在考驗自己面臨未知事物的勇氣嗎?
勇敢的踏出冒險的旅程吧!

LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	setup();
	call_other( "/obj/board/time-limit_b", "???" );
	call_other( "/obj/board/13_luck_b", "???" );
	
	}
