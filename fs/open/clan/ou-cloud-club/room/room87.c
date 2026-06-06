inherit ROOM;
void create() {
	set( "short", "建國千年祭廣場" );
	set( "item_desc", ([
		"statue" : @ITEM
冰焰雕像居然緩緩活動了起來... 
冰焰冷笑道: 「憑你這廢柴根本就不是我的班數, 也想來跟我鬥, 這就給我去仆街吧。」

看來冰焰想殺死你﹗

冰焰吼道:是你逼我使用 穹蒼無悔的!!去見閻王吧!!

你避無可避﹐霎時被高速而來的血龍捲風捲成一團﹐被旋風拉扯的痛楚有如撕肝裂肺﹗
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )
「穹蒼無悔」使出後，冰焰大耗內力、天闕穴驟然疼痛，頹然跪倒在地
一道火舌由絕焱激射而出， 直接射入你的心坎。
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )
萬道冰箭由寒冰激射而出，射入你各大要穴。
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )

你的眼前一黑﹐接著什麼也不知道了.... 
 
你死了

陰曹入口  -
    你已經來到了陰間的入口。雖然距離地府還有一段距離，但是你已經
感受到陣陣刺骨的陰風。四周一片荒涼，但是卻鬼影幢幢，看來這邊的夜
總會蠻熱鬧的，應該不愁沒伴。南邊和上面好像是和人世間相通的管道，
不過好像有一股無形的力量隔開這兩個不同的世界，看來要從這兩個方向
回去不是那麼簡單的事情。

    這裡明顯的出口是 north
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10260 );
	set( "object", ([
		"file3"    : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/xisuidan",
		"file7"    : "/open/mogi/castle/obj/blood-water",
		"file9"    : "/obj/gift/xisuidan",
		"file2"    : "/obj/gift/xisuidan",
		"amount9"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"amount10" : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file5"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"file1"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"amount1"  : 1,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room121.c",
		"enter"     : "/open/clan/ou-cloud-club/room/room155.c",
		"east"      : "/open/clan/ou-cloud-club/room/room479",
		"out"       : "/open/clan/ou-cloud-club/room/room320.c",
		"up"        : "/open/clan/ou-cloud-club/room/room409",
		"north"     : "/open/clan/ou-cloud-club/room/room109.c",
		"down"      : "/open/clan/ou-cloud-club/room/room96.c",
	]) );
	set( "long", @LONG
廣場響起一陣鐘聲.溫暖的陽光,透過茂密的松林,像格子般灑在地上,
建國千年祭典在這裡熱鬧的舉行了,在這邊你可以看到各式各樣別富文化
特色的展示攤位,兩個小孩與一隻小黃狗在你面前追逐而過,在如此和平的
時代中,許多關於世界過去的戰爭,災難等彷彿已遙遠的被遺忘了,但在這
廣場上,卻依晰能夠見到那些曾經被人津津樂道歌頌著的古老神話,然而誰
知,就在廣場的某一角落,隱藏著聯繫過去與未來世界命運的亙古謎團...,
廣場正中央是個巨大石像(statue),紀念著一位曾捨身入魔,只為消彌入侵
者的千古英魂

    ζ天焰武神ζ「捨身入魔」冰焰紀念雕像(statue) 
LONG);
	setup();
	replace_program(ROOM);
}
