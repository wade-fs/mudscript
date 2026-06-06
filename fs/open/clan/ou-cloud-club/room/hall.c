// Room : /open/clan/ou-cloud-club/room/hall.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
一踏入此地‧‧‧便有一股傲情俠骨的氣息朝你直撲而來
‧‧‧原來這便是傳說中仙意靈地的$HIY$傲$HIC$雲$HIB$山$HIR$莊$NOR$，據說當年乃此
莊主劍君十二恨召集武林上赫赫有名的$HIC$雪蒼$NOR$、$HIR$瀧山$NOR$、$HIM$聖火$NOR$、仙
劍、$MAG$儒門$NOR$、$HIG$段家$NOR$、$YEL$舞者$NOR$、殺手、$CYN$惡人$NOR$、$HIB$魔刀$NOR$、$HIY$金刀$NOR$的各派的第
一強者，窮盡畢生功力合力所創出來的空間，而莊主也為了武
林的安危，便立下重誓，要幫眾一生除$HIR$惡$NOR$懲$HIC$奸$NOR$，如此情操早已
令$HIY$傲$HIC$雲$HIB$山$HIR$莊$NOR$成為全天下第一大幫了‧‧‧
 

                       $HIC$ ;;;;''
                          ,
                         ,;;,;'''';;;
                  , ,,;''';; ,,  '''
                ;;       ;; ;;
                ;;   ;;  ;' ,;'
                            ,
                       ,;;'''',,,,
                        ,,,;''''  '
                  ,,;;'',;;   ,
                        ,;',,,;';,
                      ';;;''   ' $NOR$

LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 7 */
		"east"      : "/open/clan/ou-cloud-club/room/room6.c",
		"enter"     : "/open/clan/ou-cloud-club/room/room162.c",
		"north"     : "/open/clan/ou-cloud-club/room/room9",
		"up"        : "/open/clan/ou-cloud-club/room/room118",
		"down"      : "/open/clan/ou-cloud-club/room/room131.c",
		"south"     : "/open/clan/ou-cloud-club/room/room126.c",
		"west"      : "/open/clan/ou-cloud-club/room/room2.c",
]) );
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "short", "$HIY$傲$HIC$雲$HIB$山$HIR$莊$NOR$" );
	set( "item_desc", ([
		"statue" : @ITEM

雕像發出萬道耀眼寒光, 傳說中最接近神的男人--劍君十二恨出現了!!

劍君十二恨轉頭大喝: 「 你這廢柴小輩休想毀我基業, 只要有我在的一天,　傲雲便沒可能倒的啊。」

看來劍君十二恨想殺死你﹗

只見劍君十二恨把瀧山派與雪蒼派的絕學融合一致，使出『寒冰烈火掌』向妳狂攻而去。
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )
只見劍君十二恨把瀧山派與雪蒼派的絕學融合一致，使出『寒冰烈火掌』向妳狂攻而去。
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )
只見劍君十二恨把瀧山派與雪蒼派的絕學融合一致，使出『寒冰烈火掌』向妳狂攻而去。
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )
只見劍君十二恨把瀧山派與雪蒼派的絕學融合一致，使出『寒冰烈火掌』向妳狂攻而去。
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )
只見劍君十二恨把瀧山派與雪蒼派的絕學融合一致，使出『寒冰烈火掌』向妳狂攻而去。
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )
只見劍君十二恨把瀧山派與雪蒼派的絕學融合一致，使出『寒冰烈火掌』向妳狂攻而去。
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )
只見劍君十二恨把瀧山派與雪蒼派的絕學融合一致，使出『寒冰烈火掌』向妳狂攻而去。
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )
只見劍君十二恨把瀧山派與雪蒼派的絕學融合一致，使出『寒冰烈火掌』向妳狂攻而去。
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )
只見劍君十二恨把瀧山派與雪蒼派的絕學融合一致，使出『寒冰烈火掌』向妳狂攻而去。
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )
只見劍君十二恨把瀧山派與雪蒼派的絕學融合一致，使出『寒冰烈火掌』向妳狂攻而去。
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
	set( "object", ([
		"file3"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount9"  : 1,
		"file9"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount3"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file6"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount10" : 1,
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
	]) );
	set( "build", 16691 );
	set( "no_transmit", 1 );
	setup();                                             
	call_other( "/obj/board/ou-cloud-club_b", "???" );
	}
