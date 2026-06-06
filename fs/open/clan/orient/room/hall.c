// Room : /open/clan/demon_castle/room/hall.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$『$HIC$臥雲正廳$HIW$』$NOR$" );
	set( "exits", ([
		"up"        : "/open/clan/orient/room/room37.c",
		"enter"     : "/open/clan/orient/room/room63",
		"north"     : "/open/clan/orient/room/room3",
		"west"      : "/open/clan/orient/room/room2.c",
		"down"      : "/open/clan/orient/room/room5",
		"east"      : "/open/clan/orient/room/room4",
	]) );

	set( "build", 873 );
	set( "light_up", 1 );
	set( "no_transmit", 1 );
	set( "long", @LONG

    煙雨江南正廳臥雲，取「放仙雲臥，煙雨嵐祥」之寓以取之。廳首廳
首匾額上書『臥雲』二字，復有對聯，皆鐵劃銀鉤行雲流水寓憑風之意；
上首置紫檀木桌椅，桌上養著一盆牡丹，扶手椅背雕以奇花異草，含苞待
放似吐清芬，又置織錦椅墊上繡歲寒蠟梅，頗富情韻；樑上處處懸掛茜紗
燈籠，飾以盤長磬結綴以流蘇，更添華麗；兩側粉牆上闢八角漏窗，借屋
外園林勝景為圖畫。
    內廳提書『臥雲江南』，書法筆勢蒼翠雋潔，左右提聯赤朱紙配其字
，筆力遒勁入木三分有沖天之勢；聯下置黑檀木桌椅並以雲南理石作雲彩
狀配之，扶手椅背雕以飛禽走獸，昂然似躍栩栩如生，又置織錦椅墊上繡
荷塘春色，頗富情韻；樑上處處懸掛茜紗燈籠，飾以盤長磬結綴以流蘇，
更添華麗；兩側粉牆上闢八角漏窗，借屋外園林勝景為圖畫；北側門屏後
鏤空及地窗櫺一字排開，屋後湯湯流水與池上徐來清風吹得人有出凡之想
。如道是:

              逐勝歸來雨未晴，樓前風重草煙輕，

                      谷鶯語軟花邊過，水調聲長醉裏聽。

LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	setup();
	call_other( "/obj/board/orient_b", "???" );
	}
