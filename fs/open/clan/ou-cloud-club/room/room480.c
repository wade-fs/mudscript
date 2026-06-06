inherit ROOM;
void create() {
	set( "short", "$HIR$邪‧心‧界$NOR$" );
	set( "owner", "moonsword" );
	set( "object", ([
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file7"    : "/open/dancer/obj/yuawaist",
		"amount5"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount4"  : 29,
	]) );
	set( "light_up", 1 );
	set( "build", 10386 );
	set( "item_desc", ([
		"blader_cloud" : @ITEM
湛江雲冷笑道: 「憑你這廢柴根本就不是我的班數, 也想來跟我鬥, 這就給我去仆街吧。」

看來湛江雲想殺死你﹗

湛江雲手持冷燄刀，引燃藍色之火，似燄非燄，暴喝一聲『湛藍‧冷燄』，
揚刀飛舞，式式飄飛翻動，氣化千刃，你閃避不及，刀氣已貫體而過！！
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
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room236",
	]) );
	set( "long", @LONG
沿著走道緩緩前進，來到了一間空間廣闊的石室，光線是從
較為上層的石壁透光而來，石室的正中央放著一個琉璃座，上面
放著一把水藍色的刀，隱隱泛著誘人的藍光，當你接近的時候突
然感覺到一股妖氣在空氣中瀰漫，四週的聲音彷彿都被在一瞬間
被抽空，只有你的心跳聲依然撲通、撲通的在耳邊圍繞。

  冷燄‧刀狂  湛江雲(Blader_cloud)

LONG);
	setup();
	replace_program(ROOM);
}
