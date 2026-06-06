inherit ROOM;
void create() {
	set( "short", "$HIC$天空之城$NOR$--$HIM$糖$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/obj/gift/bingtang",
		"file7"    : "/obj/gift/lingzhi",
		"amount7"  : 1,
		"file2"    : "/obj/gift/bingtang",
		"file9"    : "/obj/gift/bingtang",
		"amount2"  : 1,
		"amount9"  : 1,
	]) );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room210",
	]) );
	set( "owner", "del" );
	set( "light_up", 1 );
	set( "build", 10039 );
	set( "item_desc", ([
		"swordsman" : @ITEM
緋天劍邪突然轉過頭來瞪你一眼。
緋天劍邪冷笑道: 「憑你這廢柴根本就不是我的班數, 也想來跟我鬥, 這就給我去仆街吧」
ˉ
看起來緋天劍邪想殺死你！
ˉ
緋天劍邪吼道: 見閻王去吧！看我的『殺禪七劍』！！
ˉ
霎時間風雲變色，雷聲大作，緋天劍邪手中的殺禪已穿體而過！！
( 你已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。 )
        [ 精力: -1  氣血: -1  神瞑: -1 ]
ˉ
你的眼前一黑﹐接著什麼也不知道了.... 
ˉ
你死了
ˉ
陰曹入口  -
ˉˉ你已經來到了陰間的入口。雖然距離地府還有一段距離，但是你已經
感受到陣陣刺骨的陰風。四周一片荒涼，但是卻鬼影幢幢，看來這邊的夜
總會蠻熱鬧的，應該不愁沒伴。南邊和上面好像是和人世間相通的管道，
不過好像有一股無形的力量隔開這兩個不同的世界，看來要從這兩個方向
回去不是那麼簡單的事情。
ˉ
ˉˉ這裡明顯的出口是 north
ˉ
ITEM,
	]) );
	set( "long", @LONG
推開半掩的木門，陣陣清香迎面而來，令人精神為之一
振，環顧四週，只有簡單的擺設，卻又不會覺得簡陋，這大
概跟主人的獨特氣質有關吧。不遠處有一用深藍色布幕隔開
的小門，隱約傳來沙沙的聲音，不曉得藏著什麼。
ˉ
ˉ傲雲七聖『劍心劍意劍通神』緋天劍邪(Evil_swordsman)
ˉ
LONG);
	setup();
	replace_program(ROOM);
}
